

if (INSTALL_WIN_DEPS)

	if (NOT WIN32)
		message(FATAL_ERROR "Can only INSTALL_WIN_DEPS on Windows!")
	endif(NOT WIN32)
	
	if (MSVC)
		set(DEPENDENCY_INSTALL_DIR ${CMAKE_SOURCE_DIR}/deps/install-MSVC)
	elseif(MINGW)
		set(DEPENDENCY_INSTALL_DIR ${CMAKE_SOURCE_DIR}/deps/install-mingw)
	else(MSVC)
		message(FATAL_ERROR "Only MinGW and MSVC are supported for installing deps")
	endif(MSVC)
	
	set(DEPENDENCY_EXTRACT_DIR  ${CMAKE_SOURCE_DIR}/deps/extract)
    set(DEPENDENCY_DOWNLOAD_DIR ${CMAKE_SOURCE_DIR}/deps/download)
    include(cmake/get-sdl2.cmake)
    include(cmake/get-sdl2_image.cmake)
    include(cmake/get-glew.cmake)
    return()

elseif(WIN32)
	
	
	if (MINGW)
		list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/deps/install-mingw)
		string(REPLACE "/" "\\" WINDOWS_SOURCE_DIR "${CMAKE_SOURCE_DIR}")
		string(REPLACE "/" "\\" WINDOWS_BINARY_DIR "${CMAKE_BINARY_DIR}")
		string(CONCAT RUN_BAT_SRC
			"@echo off\r\n"
			"SET PATH=${WINDOWS_SOURCE_DIR}\\deps\\install-mingw\\bin;%PATH%\r\n"
			"cmake --build . -- -j\r\n"
			"${WINDOWS_BINARY_DIR}\\Runner\\runner.exe")
		file(GENERATE 
			OUTPUT ${CMAKE_BINARY_DIR}/run.bat
			CONTENT "${RUN_BAT_SRC}")
	elseif(MSVC)
		list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/deps/install-MSVC)
		string(REPLACE "/" "\\" WINDOWS_SOURCE_DIR "${CMAKE_SOURCE_DIR}")
		string(REPLACE "/" "\\" WINDOWS_BINARY_DIR "${CMAKE_BINARY_DIR}")
		string(CONCAT RUN_BAT_SRC
			"@echo off\r\n"
			"SET PATH=${WINDOWS_SOURCE_DIR}\\deps\\install-MSVC\\bin;%PATH%\r\n"
			"SET config=Debug\r\n"
			"IF \"%1\"==\"Release\" (SET config=Release)\r\n"
			"cmake --build . --config %config%\r\n"
			"${WINDOWS_BINARY_DIR}\\Runner\\%config%\\runner.exe")
		file(GENERATE
			OUTPUT ${CMAKE_BINARY_DIR}/run.bat
			CONTENT "${RUN_BAT_SRC}")
	endif(MINGW)

endif(INSTALL_WIN_DEPS)
