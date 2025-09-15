add_library(core STATIC)
target_sources(core
    PRIVATE
        core.cpp include/core/core.h
)
target_include_directories(core
    PRIVATE
        include/core
    PUBLIC
        include
)
