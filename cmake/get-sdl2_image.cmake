
include(ExternalProject)

set(SDL2_IMAGE_VERSION "2.0.4")

if(NOT WIN32)
    message("This is for Windows only")
endif(NOT WIN32)

if(MINGW) # download pre-compiled SDL2 dev package for MinGW 32/64-bit

    ExternalProject_Add(
        sdl2-image
        DEPENDS sdl2
        PREFIX ${DEPENDENCY_EXTRACT_DIR}
        DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
        URL https://libsdl.org/projects/SDL_image/release/SDL2_image-devel-${SDL2_IMAGE_VERSION}-mingw.tar.gz  
        URL_MD5 53fd232ce4d70a3af18909a8a7248094
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND 
		COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCY_INSTALL_DIR}/bin/ ${DEPENDENCY_INSTALL_DIR}/lib/ ${DEPENDENCY_INSTALL_DIR}/include/
        COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/lib/libSDL2_image.dll.a  
			${DEPENDENCY_INSTALL_DIR}/lib/libSDL2_image.dll.a
		COMMAND ${CMAKE_COMMAND} -E copy
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/SDL2_image.dll
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/libjpeg-9.dll
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/libpng16-16.dll
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/libtiff-5.dll
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/libwebp-7.dll
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/bin/zlib1.dll
			${DEPENDENCY_INSTALL_DIR}/bin/
        COMMAND ${CMAKE_COMMAND} -E copy_directory
			${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/x86_64-w64-mingw32/include/SDL2
			${DEPENDENCY_INSTALL_DIR}/include/SDL2
        )

endif(MINGW)

if(MSVC) # download pre-compiled SDL2 dev package for Visual C++ 32/64-bit

    ExternalProject_Add(
        sdl2-image
        DEPENDS sdl2
        PREFIX ${DEPENDENCY_EXTRACT_DIR}
        DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
        URL https://libsdl.org/projects/SDL_image/release/SDL2_image-devel-${SDL2_IMAGE_VERSION}-VC.zip
        URL_MD5 9435e3ecc2f03eed6a24c7ed2dd96d99
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND 
            COMMAND ${CMAKE_COMMAND} -E copy
                ${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/SDL2_image.lib
                ${DEPENDENCY_INSTALL_DIR}/lib/
            COMMAND ${CMAKE_COMMAND} -E copy
				${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/SDL2_image.dll
                ${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/libjpeg-9.dll
				${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/libpng16-16.dll
				${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/libtiff-5.dll
				${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/libwebp-7.dll
				${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/lib/x64/zlib1.dll
                ${DEPENDENCY_INSTALL_DIR}/bin/
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${DEPENDENCY_EXTRACT_DIR}/src/sdl2-image/include 
                ${DEPENDENCY_INSTALL_DIR}/include/SDL2
        )

endif(MSVC)
