# Check whether all the dependencies are installed properly
add_executable(dependency_versions
    deps.c
)
target_link_libraries(dependency_versions
    PRIVATE
        SDL2::SDL2main
    PUBLIC
        engine
)
add_test(NAME deps COMMAND dependency_versions)
