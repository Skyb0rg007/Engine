
include(ExternalProject)

if(NOT WIN32)
    message("This is for Windows only")
endif(NOT WIN32)

set(GLEW_VERSION "2.1.0")

if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
	ExternalProject_Add(
		glew
		PREFIX ${DEPENDENCY_EXTRACT_DIR}
		DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
		URL https://downloads.sourceforge.net/project/glew/glew/${GLEW_VERSION}/glew-${GLEW_VERSION}-win32.zip
		URL_MD5 32a72e6b43367db8dbea6010cd095355
		CONFIGURE_COMMAND ""
		BUILD_COMMAND ""
		INSTALL_COMMAND
			COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCY_INSTALL_DIR}/bin/ ${DEPENDENCY_INSTALL_DIR}/lib/ ${DEPENDENCY_INSTALL_DIR}/include/
			COMMAND ${CMAKE_COMMAND} -E copy
				${DEPENDENCY_EXTRACT_DIR}/src/glew/bin/Release/x64/glew32.dll
				${DEPENDENCY_INSTALL_DIR}/bin/
			COMMAND ${CMAKE_COMMAND} -E copy
				${DEPENDENCY_EXTRACT_DIR}/src/glew/lib/Release/x64/glew32.lib
				${DEPENDENCY_INSTALL_DIR}/lib/
			COMMAND ${CMAKE_COMMAND} -E copy_directory
				${DEPENDENCY_EXTRACT_DIR}/src/glew/include/GL/
				${DEPENDENCY_INSTALL_DIR}/include/GL
	)
elseif()
	message(FATAL_ERROR "32 bit not yet implemented")
endif()