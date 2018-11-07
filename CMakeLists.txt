cmake_minimum_required(VERSION 3.9.6)
project(GL_Engine
    VERSION 0.1.0
    DESCRIPTION "Testing OpenGL and SDL2"
    LANGUAGES C
)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds are not allowed")
endif()

# Add custom Find*.cmake files to the search path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# All possible cmake options
option(INSTALL_WIN_DEPS "Install SDL2, SDL2_image, and GLEW for Windows" OFF)
option(DISABLE_ATTRIBUTES "Disables optimising attributes" OFF)
option(USE_ASAN "Compiles with AddressSanitizer for Debug builds - Linux only" OFF)
option(ENABLE_TESTS "Enable the tests for this project" OFF)

include(cmake/handle-windows.cmake)
if (INSTALL_WIN_DEPS)
    return()
endif(INSTALL_WIN_DEPS)

# Load all the needed packages
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL 3.3 REQUIRED)
find_package(SDL2 2.0 REQUIRED) # This uses the custom FindSDL2.cmake script
find_package(SDL2_image 2.0 REQUIRED) # Same, FindSDL2_image.cmake
find_package(GLEW 2.1 REQUIRED)
find_package(Doxygen OPTIONAL_COMPONENTS dot QUIET)

# Enable Address Sanitizer for building executables
if (USE_ASAN)
    string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG 
        " -fno-omit-frame-pointer -fsanitize=address ")
    string(APPEND CMAKE_C_FLAGS_DEBUG
        " -fno-omit-frame-pointer -fsanitize=address ")
endif(USE_ASAN)

# Enable testing if we want
if (ENABLE_TESTS)
    enable_testing()
endif(ENABLE_TESTS)

# Enable document building if we have Doxygen
if (DOXYGEN_FOUND)
    doxygen_add_docs(docs
        ${CMAKE_SOURCE_DIR}/Engine
        ${CMAKE_SOURCE_DIR}/Runner
        COMMENT "Build documentation")
endif(DOXYGEN_FOUND)

# supplementary libraries
add_subdirectory(libs/cglm) # cglm interface library
add_subdirectory(libs/klib) # klib interface library

# Location for shaders and other resources
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources/")

# the main library
add_subdirectory(Engine)
# the executable
add_subdirectory(Runner)
