add_library(ecs STATIC)
target_sources(ecs
    PRIVATE
                      include/ecs/ecs.h
        archetype.cpp include/ecs/archetype.h
        componentarray.cpp include/ecs/componentarray.h
                           include/ecs/system.h
                           include/ecs/executionrestraints.h
)
target_include_directories(ecs
    PRIVATE
        include/ecs
    PUBLIC
        include
)
target_link_libraries(ecs
    PUBLIC
        ts
)


