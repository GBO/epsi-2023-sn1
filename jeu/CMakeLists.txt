cmake_minimum_required(VERSION 3.21)
project(ProjetC LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(ProjetC main.cpp main.cpp main.cpp main.cpp combat.cpp combat.h)
target_link_libraries(ProjetC PRIVATE sfml-graphics)
target_link_libraries(ProjetC PRIVATE sfml-graphics sfml-audio)

target_compile_features(ProjetC PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ProjetC POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ProjetC> $<TARGET_FILE_DIR:ProjetC> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ProjetC)
