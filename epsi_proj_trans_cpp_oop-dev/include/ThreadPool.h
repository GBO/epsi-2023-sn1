//
// Created by Killian on 17/03/2023.
//

#pragma once

#include <deque>

////////////////////////////////////////////////////////////
/// \brief  A class which defines a thread pool
///
/// A thread pool is a group of threads which are used to execute
/// tasks asynchronously. This can for example be used to load resources
/// while the game is running. You can enqueue tasks in the thread pool
/// using the Enqueue function. When a thread is available, it will
/// execute the task.
///
/// When the thread pool isn't needed anymore, you can call Terminate()
/// to stop the threads. The destructor will not stop the threads, as
/// this will cause access violations when logging is used.
///
/// After calling Terminate(), you can call Init() to restart the
/// threads.
///
////////////////////////////////////////////////////////////
class ThreadPool
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief  Default constructor
    ///
    /// This will not create any threads. You must call Init() to
    /// create the threads.
    ///
    /// \see Init()
    ///
    ////////////////////////////////////////////////////////////
    ThreadPool() = default;

    ////////////////////////////////////////////////////////////
    /// \brief  Initializes the thread pool
    ///
    /// This will create the threads and start them. You must call
    /// this function before you can enqueue tasks.
    ///
    /// The number of threads created will be equal to the number
    /// of hardware threads minus one. This is because the main
    /// thread will also be used to execute tasks.
    ///
    ////////////////////////////////////////////////////////////
    void Init();

    ////////////////////////////////////////////////////////////
    /// \brief  Enqueues a task
    ///
    /// This will enqueue a task in the thread pool. When a thread
    /// is available, it will execute the task.
    ///
    /// \tparam F the type of the function
    /// \tparam Args the types of the arguments
    /// \param f the function provided as a task
    /// \param args the arguments to pass to the function
    ///
    ////////////////////////////////////////////////////////////
    template<typename F, typename... Args>
    void Enqueue(F&& f, Args&&... args)
    {
        {
            // Lock the mutex and add the task to the queue
            std::unique_lock<std::mutex> lock(m_mutex);
            m_tasks.emplace_back(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        }
        // Notify a thread that a task is available
        m_condition.notify_one();
    }

    ////////////////////////////////////////////////////////////
    /// \brief  Terminates the thread pool
    ///
    /// This will stop the threads and clear the task queue. You
    /// can call Init() to restart the threads.
    ///
    /// \see Init()
    ///
    ////////////////////////////////////////////////////////////
    void Terminate();

    ////////////////////////////////////////////////////////////
    /// \brief  Rethrow any exceptions that occurred in the threads
    ///
    /// This will rethrow any exceptions that occurred in the threads.
    /// If no exceptions occurred, this function will do nothing.
    ///
    ////////////////////////////////////////////////////////////
    void RethrowExceptions();

private:
    std::vector<std::thread> m_threads;
    std::mutex m_mutex;
    std::condition_variable m_condition;
    std::deque<std::function<void()>> m_tasks;
    std::atomic_bool m_shouldStop = false;
    std::atomic_int m_nextThreadId = 0;
    std::vector<std::exception_ptr> m_exceptions;
    std::mutex m_exceptionMutex;
    std::condition_variable m_creationCondition;
};