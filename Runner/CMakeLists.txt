add_executable(runner
    src/main.c
)
target_link_libraries(runner
    PUBLIC
        engine
        SDL2::SDL2main
)

add_subdirectory(tests)
