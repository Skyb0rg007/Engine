project(cglm
    VERSION 0.4.6
    DESCRIPTION "Optimized matrix library - glm for C"
    LANGUAGES C
)

add_library(cglm INTERFACE)
target_include_directories(cglm
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(cglm
    INTERFACE
        $<$<NOT:$<C_COMPILER_ID:MSVC>>:m>)
target_compile_features(cglm
    INTERFACE
        c_std_99
)
