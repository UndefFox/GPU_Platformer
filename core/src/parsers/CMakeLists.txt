add_library(parsers STATIC)
target_sources(parsers
    PRIVATE
        fon.cpp include/parsers/fon.h
)
target_include_directories(parsers
    PRIVATE
        include/parsers
    PUBLIC
        include
)


