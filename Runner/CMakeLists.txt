add_executable(runner WIN32
    src/main.c
)
target_link_libraries(runner
    PUBLIC
        engine
)

add_subdirectory(tests)
