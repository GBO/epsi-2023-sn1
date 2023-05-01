//
// Created by Killian on 14/03/2023.
//

#pragma once

#include <memory>
#include <utility>
#include <Scene.h>
#include <ResourceRegistry.h>
#include <ThreadPool.h>

#undef CreateWindow

////////////////////////////////////////////////////////////
/// \brief  A singleton class which defines the application
///
////////////////////////////////////////////////////////////
class Application
{
public:
    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

    ////////////////////////////////////////////////////////////
    /// \brief  Returns the instance of the application
    ///
    /// When this function is called for the first time, it will create
    /// the application
    ///
    /// \return A reference to the application
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] static inline Application& GetInstance()
    {
        if (!s_instance)
        {
            s_instance = std::unique_ptr<Application>(new Application());
        }

        return *s_instance;
    }

    ////////////////////////////////////////////////////////////
    /// \brief  Starts the main loop and run it, until the user closes
    ///         the application or an error occurs
    ///
    ////////////////////////////////////////////////////////////
    void RunMainLoop();

    ////////////////////////////////////////////////////////////
    /// \brief  Returns the texture registry
    ///
    /// The texture registry is used to load and store textures.
    ///
    /// \return A reference to the texture registry
    ///
    /// \see TextureRegistry
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] inline TextureRegistry& GetTextureRegistry() { return m_textureRegistry; }

    ////////////////////////////////////////////////////////////
    /// \brief  Returns the font registry
    ///
    /// The font registry is used to load and store fonts.
    ///
    /// \return A reference to the font registry
    ///
    /// \see FontRegistry
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] inline FontRegistry& GetFontRegistry() { return m_fontRegistry; }

    ////////////////////////////////////////////////////////////
    /// \brief  Returns the thread pool
    ///
    /// The thread pool is used to execute tasks asynchronously.
    ///
    /// \return A reference to the thread pool
    ///
    /// \see ThreadPool
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] inline ThreadPool& GetThreadPool() { return m_threadPool; }


    [[nodiscard]] inline uint32_t GetWindowWidth() const { return m_windowWidth; }
    [[nodiscard]] inline uint32_t GetWindowHeight() const { return m_windowHeight; }
    [[nodiscard]] inline float GetAspectRatio() const { return static_cast<float>(m_windowWidth) / static_cast<float>(m_windowHeight); }

    static constexpr std::string_view WINDOW_TITLE = "Harvest Haven";
    static constexpr float ZOOM_FACTOR = 1.0f;

protected:
    friend ThreadPool;

    ////////////////////////////////////////////////////////////
    /// \brief  Returns the context id
    ///
    /// The context id is used to identify the OpenGL context.
    /// This function is only used internally.
    ///
    /// \return The context id
    ///
    ////////////////////////////////////////////////////////////
#ifdef _WIN32
    [[nodiscard]] HGLRC GetContextId() { return m_contextId; }
#else
#error Not Supported!
#endif

protected:
    friend ThreadPool;

    ////////////////////////////////////////////////////////////
    /// \brief  Adds a context to the list of contexts
    ///
    /// This function is used to add a context to the list of contexts
    /// and to share its resource with the main context
    ///
    /// \param context The context to add
    ///
    ////////////////////////////////////////////////////////////
#ifdef _WIN32
    void AddContext(HGLRC context);
#else
#error Not Supported!
#endif


private:
    ////////////////////////////////////////////////////////////
    /// \brief  The default constructor
    ///
    /// Creates the window and initializes the subsystems (RNG,
    /// Networking, Audio...)
    ///
    ////////////////////////////////////////////////////////////
    Application();

    ////////////////////////////////////////////////////////////
    /// \brief  Update the frame based on the time the last frame took
    ///
    /// All physics calculations and logic should happen here.
    ///
    /// \param deltaTime The time in seconds the last frame took
    ///
    ////////////////////////////////////////////////////////////
    void Update(float deltaTime);

    ////////////////////////////////////////////////////////////
    /// \brief  Renders the frame to the screen
    ///
    /// All rendering calls should happen here
    ///
    ////////////////////////////////////////////////////////////
    void Render();

    ////////////////////////////////////////////////////////////
    /// \brief  Creates the window
    ///
    /// \param mode The video mode to use
    /// \param fullscreen Whether the window should be fullscreen
    ///
    ////////////////////////////////////////////////////////////
    void CreateWindow(sf::VideoMode mode, bool fullscreen);

    static constexpr uint32_t DEFAULT_WINDOW_WIDTH = 1280;
    static constexpr uint32_t DEFAULT_WINDOW_HEIGHT = 720;


    static std::unique_ptr<Application> s_instance;

    uint32_t m_windowWidth = DEFAULT_WINDOW_WIDTH;
    uint32_t m_windowHeight = DEFAULT_WINDOW_HEIGHT;
    sf::RenderWindow m_window;
    bool m_fullscreen = false;

    bool m_running = true;
    float m_timer = 0.0f;
    uint16_t frames = 0;
    sf::Clock m_clock;

    TextureRegistry m_textureRegistry;
    FontRegistry m_fontRegistry;
    ThreadPool m_threadPool;

    std::unique_ptr<Scene> m_currentScene;

#ifdef _WIN32
    HGLRC m_contextId;
    std::vector<HGLRC> m_threadsContext;
#else
#error Not Supported!
#endif

    std::mutex m_threadsContextMutex;
};
