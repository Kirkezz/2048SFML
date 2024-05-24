cmake_minimum_required(VERSION 3.16)
project(2048SFML LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(2048SFML main.cpp Game.h Game.cpp Renderer.h Renderer.cpp)
target_link_libraries(2048SFML PRIVATE sfml-graphics)
target_compile_features(2048SFML PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:2048SFML>
        VERBATIM)
endif()


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CimeroPro.otf ${CMAKE_BINARY_DIR}/bin/CimeroPro.otf COPYONLY)

install(TARGETS 2048SFML)
