configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h
    @ONLY
)

if (ENGINE_BUILD_DYNAMIC)
    set(ENGINE_LIB_TYPE SHARED)
else()
    set(ENGINE_LIB_TYPE STATIC)
endif(ENGINE_BUILD_DYNAMIC)

add_library(engine ${ENGINE_LIB_TYPE}
    src/main.c
    src/glutils.c
    src/utils.c
    src/ECS/ECS.c
)
target_link_libraries(engine
    INTERFACE
        SDL2::SDL2main
    PUBLIC
        OpenGL::GL
        GLEW::GLEW
        SDL2::SDL2
        SDL2::SDL2_image
    PRIVATE
        cglm
        klib
)
target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/public
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(engine
    PUBLIC
        $<$<COMPILE_FEATURES:c_std_11>:c_std_11>
        $<$<NOT:$<COMPILE_FEATURES:c_std_11>>:c_std_99>
)
target_compile_options(engine
    PRIVATE
        $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:
            -Wall -Wextra -pedantic
            -Wformat=2 -Wwrite-strings -Wstrict-overflow=5
            -Winline -Wnested-externs 
            -Wno-double-promotion
            -Wshadow -Wformat=2
            -fno-common
            # if I hate myself
            # -Wconversion
        >
        $<$<C_COMPILER_ID:GNU>:
            -Wlogical-op -Wstrict-aliasing=2
            -Wjump-misses-init
        >
)
if (ENGINE_BUILD_DYNAMIC)
    target_compile_definitions(engine
        PRIVATE
            BUILDING_ENGINE_DLL
        INTERFACE
            INCLUDING_ENGINE_DLL
    )
endif(ENGINE_BUILD_DYNAMIC)

# Testing
add_subdirectory(tests)
