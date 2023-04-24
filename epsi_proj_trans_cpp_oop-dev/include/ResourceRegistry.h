//
// Created by Killian on 16/03/2023.
//

#pragma once

#include <unordered_set>
#include <mutex>
#include <SFML/Graphics/Texture.hpp>

#ifdef DEBUG
#define DEFINE_REGISTRY(path, type) \
    constexpr const char type##Path[] = path; \
    constexpr const char type##Name[] = #type;\
    typedef ResourceRegistry<type##Path, type, type##Name> type##Registry;
template <char const* BASE_PATH, typename T, const char* TYPE_NAME>
#else
#define DEFINE_REGISTRY(path, type) \
    constexpr const char type##Path = path; \
    ResourceRegistry<type##Path, type>
template <char const* BASE_PATH, typename T>
#endif
////////////////////////////////////////////////////////////
/// \brief  A registry for resources
///
/// This class is used to register resources and to get a
/// handle to them. The resources are loaded only once and
/// are kept in memory until the last handle is destroyed.
///
/// \tparam BASE_PATH the base path of the resources
/// \tparam T the type of the resources
/// \tparam TYPE_NAME the name of the type of the resources
///         (only available on debug)
///
////////////////////////////////////////////////////////////
class ResourceRegistry
{
public:
    ResourceRegistry() = default;
    ResourceRegistry(const ResourceRegistry&) = delete;
    ResourceRegistry(ResourceRegistry&&) = delete;
    ResourceRegistry& operator=(const ResourceRegistry&) = delete;
    ResourceRegistry& operator=(ResourceRegistry&&) = delete;

    //////////////////////////////////////////////////////////////
    /// \brief  A handle to a resource
    ///
    /// This class is used to get a reference to a resource.
    /// This is needed because we need to keep track of the
    /// number of handles to a resource to know when to unload
    /// it. The resource is unloaded when the last handle is
    /// destroyed.
    ///
    /// You can get a handle to a resource by calling
    /// ResourceRegistry::GetResource.
    ///
    /// \see ResourceRegistry::GetResource
    ///
    //////////////////////////////////////////////////////////////
    class ResourceHandle
    {
    public:
        ResourceHandle(const ResourceHandle& other)
        {
            m_element = other.m_element;
            m_registry = other.m_registry;
            m_path = other.m_path;

            m_registry->AddReference(m_element);
        }

        ResourceHandle& operator=(const ResourceHandle& other)
        {
            m_element = other.m_element;
            m_registry = other.m_registry;
            m_path = other.m_path;

            m_registry->AddReference(m_element);
            return *this;
        }

        //////////////////////////////////////////////////////////////
        /// \brief  The default constructor.
        ///
        /// This constructor creates an empty handle. This handle cannot
        /// be used to get a reference to a resource.
        /// To create a valid handle, you need to call
        /// ResourceRegistry::GetResource.
        ///
        /// \see ResourceRegistry::GetResource
        ///
        //////////////////////////////////////////////////////////////
        ResourceHandle() = default;

        //////////////////////////////////////////////////////////////
        /// \brief  The move constructor.
        ///
        /// This constructor moves the handle to another handle. This
        /// is needed because otherwise the handle would be destroyed
        /// before the current handle is created, and thus the resource
        /// would be unloaded before it is used.
        ///
        /// \param other the handle to move
        ///
        //////////////////////////////////////////////////////////////
        ResourceHandle(ResourceHandle&& other) noexcept
        {
            m_registry = std::move(other.m_registry);
            m_element = std::move(other.m_element);
            m_path = std::move(other.m_path);

            other.m_registry = nullptr;
            other.m_element = nullptr;
            other.m_path = nullptr;
        }

        //////////////////////////////////////////////////////////////
        /// \brief  The move assignment operator.
        ///
        /// This operator does the same thing as the move constructor,
        /// except that it is used when assigning a handle to another.
        ///
        /// \param other the handle to move
        /// \return a reference to this handle
        ///
        //////////////////////////////////////////////////////////////
        ResourceHandle& operator=(ResourceHandle&& other) noexcept
        {
            m_registry = std::move(other.m_registry);
            m_element = std::move(other.m_element);
            m_path = std::move(other.m_path);

            other.m_registry = nullptr;
            other.m_element = nullptr;
            other.m_path = nullptr;

            return *this;
        }

        //////////////////////////////////////////////////////////////
        /// \brief  The resource conversion operator.
        ///
        /// This operator is used to get a reference to the resource.
        ///
        /// \return a reference to the resource
        ///
        /// \throw std::runtime_error if the handle is empty on debug builds
        ///
        //////////////////////////////////////////////////////////////
        operator const T&() const // NOLINT
        {
#ifdef DEBUG
            if(m_element == nullptr)
                throw std::runtime_error("[ResourceRegistry] Tried to retrieve the reference of an empty handle");
#endif
            return std::get<1>(*m_element);
        }

         const T* operator->() const
         {
            return &(const T&)(*this);
         }

         const T* GetPointer() const
         {
            return &(const T&)(*this);
         }

        //////////////////////////////////////////////////////////////
        /// \brief  The destructor.
        ///
        /// This destructor is used to unregister the handle from the
        /// registry if it is not empty. If the last handle is destroyed,
        /// the resource is unloaded.
        ///
        /// \see ResourceRegistry::UnregisterHandle
        ///
        //////////////////////////////////////////////////////////////
        ~ResourceHandle()
        {
            if(m_registry != nullptr)
                m_registry->UnregisterHandle(m_path, m_element);
        }

    protected:
        friend ResourceRegistry;

        //////////////////////////////////////////////////////////////
        /// \brief  The internal constructor.
        ///
        /// This constructor is used to create a handle from a registry.
        /// It is used by ResourceRegistry::GetResource.
        ///
        /// \param registry the registry that created the handle
        /// \param element the resource element
        /// \param path the path of the resource
        ///
        /// \see ResourceRegistry::GetResource
        ///
        //////////////////////////////////////////////////////////////
        ResourceHandle(ResourceRegistry* registry, std::tuple<uint64_t, T>* element, const char* path)
            : m_registry(registry), m_element(element), m_path(path)
        {}

    private:
#ifdef DEBUG
        ResourceRegistry<BASE_PATH, T, TYPE_NAME>* m_registry = nullptr;
#else
        ResourceRegistry<BASE_PATH, T>* m_registry = nullptr;
#endif

        std::tuple<uint64_t, T>* m_element;
        const char* m_path = nullptr;
    };

    //////////////////////////////////////////////////////////////
    /// \brief  Used to get a handle to a resource.
    ///
    /// This function is used to get a handle to a resource. If the
    /// resource is already loaded, it is returned. Otherwise, it is
    /// loaded and then returned.
    ///
    /// \param path the path of the resource, relative to BASE_PATH
    /// \return a handle to the resource
    /// \throw std::runtime_error if the resource cannot be loaded
    ///
    /// \see ResourceHandle
    ///
    //////////////////////////////////////////////////////////////
    ResourceHandle GetResource(const char* path)
    {
        // Lock the registry mutex to prevent multiple threads from
        // modifying the registry at the same time
        std::unique_lock<std::mutex> lock(m_registryMutex);

        if(!m_registry.contains(path))
        {
            // The resource is not loaded, so we load it

            T element;
            if(!element.loadFromFile(std::string(BASE_PATH) + path))
                throw std::runtime_error(std::string("[ResourceRegistry] Failed to load ")
                    + TYPE_NAME + " at " + BASE_PATH + path);

            // Insert the resource into the registry, with a usage count of 1
            m_registry.insert({ path, std::make_tuple(1, element) });
        }
        else
        {
            // The resource is already loaded, so we increase the usage count
            std::get<0>(m_registry[path]) += 1;
        }

        // Return a handle to the resource
        // We use std::move to avoid copying the handle
#ifdef DEBUG
        return ResourceHandle(this, &m_registry[path], path);
#else
        return ResourceHandle(*this, m_registry[path]);
#endif
    }

protected:
    friend ResourceHandle;

    //////////////////////////////////////////////////////////////
    /// \brief  Used to unregister a handle from the registry.
    ///
    /// This function is used to unregister a handle from the registry.
    /// If the last handle is unregistered, the resource is unloaded.
    ///
    /// \param path the path to the resource
    /// \param element the resource element
    ///
    /// \see ResourceHandle::~ResourceHandle
    ///
    //////////////////////////////////////////////////////////////
    void UnregisterHandle(const char* path, std::tuple<uint64_t, T>* element)
    {
        // Lock the registry mutex to prevent multiple threads from
        // modifying the registry at the same time
        std::unique_lock<std::mutex> lock(m_registryMutex);

        // Decrease the usage count of the resource
        std::get<0>(*element) -= 1;
        if(std::get<0>(*element) == 0)
        {
            // The resource is no longer used, so we unload it
            m_registry.erase(path);
        }
    }

    void AddReference(std::tuple<uint64_t, T>* element)
    {
        // Lock the registry mutex to prevent multiple threads from
        // modifying the registry at the same time
        std::unique_lock<std::mutex> lock(m_registryMutex);

        // Increase the usage count of the resource
        std::get<0>(*element) += 1;
    }

private:
    std::mutex m_registryMutex;
    std::unordered_map<const char*, std::tuple<uint64_t, T>> m_registry;
};

namespace {
    using namespace sf;
    DEFINE_REGISTRY("assets/textures/", Texture)
    DEFINE_REGISTRY("assets/fonts/", Font)
}