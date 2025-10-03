add_executable(gpu_platformer main.cpp default.hpp)


add_subdirectory(core)
add_subdirectory(ecs)
add_subdirectory(ts)
add_subdirectory(modman)


target_link_libraries(gpu_platformer
    PRIVATE
        core
        ecs
        ts
)
