add_library(core SHARED core.cpp core.h)

add_subdirectory(ts)
add_subdirectory(modman)
add_subdirectory(graphs)

target_link_libraries(core
    PRIVATE
        modman
        parsers
)
