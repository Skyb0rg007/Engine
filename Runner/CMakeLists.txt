add_executable(runner
    src/main.c
)
target_link_libraries(runner
    PUBLIC
        engine
)

add_subdirectory(tests)
