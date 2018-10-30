configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h
    @ONLY
)

add_library(engine
    src/main.c
    src/glutils.c
    src/utils.c
)
target_link_libraries(engine
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
        c_std_99
    PRIVATE
        $<$<COMPILE_FEATURES:c_static_assert>:c_static_assert>
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
# target_compile_definitions(engine
    # PRIVATE
        # BUILDING_ENGINE_LIB
# )

# Testing
add_subdirectory(tests)
