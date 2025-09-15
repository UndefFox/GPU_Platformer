add_library(ts STATIC)
set_target_properties(ts PROPERTIES LINKER_LANGUAGE CXX)
target_sources(ts
    PRIVATE
        include/ts/tagsystem.h
        include/ts/tag.h
)
target_include_directories(ts
    PRIVATE
        include/ts
    PUBLIC
        include
)


