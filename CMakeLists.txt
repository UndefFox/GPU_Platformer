cmake_minimum_required(VERSION 3.24.1)



project(gpu_platformer)


add_subdirectory(core)


install(TARGETS core DESTINATION "GPU Platformer/lib")
install(DIRECTORY DESTINATION "GPU Platformer/mods")
