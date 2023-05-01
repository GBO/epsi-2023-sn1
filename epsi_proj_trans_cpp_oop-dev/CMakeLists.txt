cmake_minimum_required(VERSION 3.24.2)
project(HarvestHaven LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git)
FetchContent_MakeAvailable(SFML)

add_executable(HarvestHaven
        src/main.cpp
        src/Application.cpp
        src/RandomNumberGenerator.cpp
        src/MainMenuScene.cpp
        src/ThreadPool.cpp
        src/GameGrid.cpp
        src/tiles/GroundTile.cpp
        src/tiles/PassagePointTile.cpp
        src/tiles/PathTile.cpp
        src/tiles/SoilTile.cpp
        src/Player.cpp
        src/GUILayer.cpp
        src/Item.cpp
        src/Inventory.cpp
        src/CollisionUtils.cpp
        src/Hotbar.cpp src/items/Hoe.cpp src/items/WateringCan.cpp src/items/Carrot.cpp)


target_include_directories(HarvestHaven PRIVATE include)
target_precompile_headers(HarvestHaven PRIVATE include/Precompiled.h)
target_link_libraries(HarvestHaven PRIVATE sfml-graphics)
target_compile_features(HarvestHaven PRIVATE cxx_std_23)
if (WIN32)
    if(BUILD_SHARED_LIBS)
        add_custom_command(TARGET HarvestHaven POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:HarvestHaven> $<TARGET_FILE_DIR:HarvestHaven> COMMAND_EXPAND_LISTS)
    endif()
    target_link_libraries(HarvestHaven PRIVATE opengl32)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG DEBUG)
endif()

install(TARGETS HarvestHaven)

add_executable(GenerateTilemap scripts/GenerateTilemap.cpp)
target_compile_features(GenerateTilemap PRIVATE cxx_std_23)