configure_file(
    ${CMAKE_SOURCE_DIR}/config.h.in 
    ${CMAKE_SOURCE_DIR}/include/config.h
    @ONLY
)

add_executable(main 
    main.c 
)
target_link_libraries(main 
    PRIVATE 
        OpenGL::GL 
        GLEW::GLEW 
        SDL2::SDL2main
        SDL2::SDL2_image
        cglm
        klib
)
target_include_directories(main 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
)
target_compile_features(main
    PRIVATE
        c_std_99
        #c_static_assert
)
target_compile_options(main
    PRIVATE
        $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:
            -Wall -Wextra -pedantic
            -Wformat=2 -Wwrite-strings -Wstrict-overflow=5
            -Winline -Wnested-externs 
            -Wno-double-promotion
            -Wshadow -Wformat=2
            -fno-common -Wfloat-equal -Wcast-align
        >
        $<$<C_COMPILER_ID:GNU>:
            -Wlogical-op -Wstrict-aliasing=2
            -Wjump-misses-init 
        >
        # if I hate myself
        # -Wconversion
)
