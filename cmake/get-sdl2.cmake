
include(ExternalProject)

if(NOT WIN32)
    message("This is for Windows only")
endif(NOT WIN32)

set(SDL2_VERSION "2.0.9")

if(MINGW) # download pre-compiled SDL2 dev package for MinGW 32/64-bit

    ExternalProject_Add(
        sdl2
        PREFIX ${DEPENDENCY_EXTRACT_DIR}
        DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
        URL http://libsdl.org/release/SDL2-devel-${SDL2_VERSION}-mingw.tar.gz
        URL_MD5 f5645eed64214c3bc22a3e157fc1f15f
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND 
		COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCY_INSTALL_DIR}/lib/ ${DEPENDENCY_INSTALL_DIR}/bin/ ${DEPENDENCY_INSTALL_DIR}/include/
        COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/x86_64-w64-mingw32/lib/libSDL2.dll.a
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/x86_64-w64-mingw32/lib/libSDL2_test.a
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/x86_64-w64-mingw32/lib/libSDL2main.a
			${DEPENDENCY_INSTALL_DIR}/lib/
        COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/x86_64-w64-mingw32/bin/SDL2.dll
			${DEPENDENCY_INSTALL_DIR}/bin/SDL2.dll
        COMMAND ${CMAKE_COMMAND} -E copy_directory
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/x86_64-w64-mingw32/include/SDL2/
			${DEPENDENCY_INSTALL_DIR}/include/SDL2/
        )

elseif(MSVC) # download pre-compiled SDL2 dev package for Visual C++ 32/64-bit

    ExternalProject_Add(
        sdl2
        PREFIX ${DEPENDENCY_EXTRACT_DIR}
        DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
        URL http://libsdl.org/release/SDL2-devel-${SDL2_VERSION}-VC.zip
        URL_MD5 22bdb85ce4874673c4fafcce772d8b72
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND 
        COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/lib/x64/SDL2.lib
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/lib/x64/SDL2main.lib
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/lib/x64/SDL2test.lib
			${DEPENDENCY_INSTALL_DIR}/lib/
        COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/lib/x64/SDL2.dll
			${DEPENDENCY_INSTALL_DIR}/bin/SDL2.dll
        COMMAND ${CMAKE_COMMAND} -E copy_directory
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2/include
			${DEPENDENCY_INSTALL_DIR}/include/SDL2/
        )

endif(MINGW)
