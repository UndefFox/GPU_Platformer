add_library(ecs STATIC)
target_sources(ecs
    PRIVATE
        ecs.cpp include/ecs/ecs.h
)
target_include_directories(ecs
    PRIVATE
        include/ecs
    PUBLIC
        include
)


