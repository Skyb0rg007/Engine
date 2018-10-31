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

### Running

    ./Runner/runner

## MacOS

### Dependencies

I recommend installing dependencies using `brew`

- cmake 3.1+
- sdl2
- sdl2\_image
- glew

### Building

See Linux building

### Running

See Linux running

## Windows

### Minimum dependencies

- cmake 3.1+
- Mingw-64 / MSVC 2017 / MSVC 2015

(I recommend MSVC 2017 if you can choose, it's easier to set up)

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

### Running

I wrote a quick batch script if you used my dependency installer
It justs runs ```.\Runner\runner.exe``` with the ```.dll```s on %PATH%

    .\run.bat
