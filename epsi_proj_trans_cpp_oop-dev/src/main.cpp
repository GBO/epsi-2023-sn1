//
// Created by Killian on 13/03/2023.
//

#include <Application.h>

int main() {

    // SPDLOG_ACTIVE_LEVEL does not set the log level internally, it juste disable
    // unneeded macros
#if SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_DEBUG
    spdlog::set_level(spdlog::level::debug);
#endif

    // Startup the application
    Application::GetInstance().RunMainLoop();
    return 0;
}

