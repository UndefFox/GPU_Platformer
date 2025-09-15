add_library(ts STATIC)
target_sources(ts
    PRIVATE
        tagsystem.cpp include/ts/tagsystem.h
)
target_include_directories(ts
    PRIVATE
        include/ts
    PUBLIC
        include
)


