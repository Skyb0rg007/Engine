[![Build Status](https://img.shields.io/travis/Skyb0rg007/Engine/master.svg?logo=travis&label=Linux%20/%20OSX)](https://travis-ci.org/Skyb0rg007/Engine)
[![Build status](https://img.shields.io/appveyor/ci/Skyb0rg007/Engine/master.svg?logo=appveyor&label=Windows)](https://ci.appveyor.com/project/Skyb0rg007/engine)

Toying around with SDL2, OpenGL, and other fun C stuff

# Installing the project

## Linux

### Dependencies

#### Ubuntu

- cmake 3.1+
- libsdl2-dev
- libsdl2\_image-dev
- glew-dev

#### Fedora

- cmake 3.1+
- SDL2-devel
- SDL2\_image-devel
- glew-devel

### Building

    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build .

## MacOS

### Dependencies

I recommend installing dependencies using `brew`

- cmake 3.1+
- SDL2
- SDL2\_image
- GLEW

## Windows

### Minimum dependencies

- cmake 3.1+
- Mingw-64 / MSVC 2017

If you have a 64-bit machine, I've written a dependency-installer for you:

    mkdir build
    cd build
    # For MinGW
        cmake .. -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND -DINSTALL_WIN_DEPS=ON
    # For MSVC 2017
	    cmake .. -G "Visual Studio 15 Win64" -DINSTALL_WIN_DEPS=ON
    # For MSVC 2015
	    cmake .. -G "Visual Studio 14 Win64" -DINSTALL_WIN_DEPS=ON
    cmake --build .
    # Wait for install, then disable the option so building will actually build the program
    cmake .. -DINSTALL_WIN_DEPS=OFF

Otherwise you will need to install the development libs for:

- SDL2 (including SDL2main)
- SDL2\_image
- GLEW

and set up the CMAKE variables to find these libraries

### Building

    # You only need to include the '--config Release' if on MSVC
    cmake --build . --config Release
