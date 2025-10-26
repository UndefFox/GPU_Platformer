add_library(core core.cpp core.h)


add_subdirectory(ts)
add_subdirectory(modman)
add_subdirectory(graphs)
add_subdirectory(parsers)


target_link_libraries(core
    PRIVATE
        ecs
        modman
        parsers
)
