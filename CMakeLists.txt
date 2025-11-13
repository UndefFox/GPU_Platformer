cmake_minimum_required(VERSION 3.24.1)



# ----- Configuration -----

project(GPUPlatformer)

set (INSTALL_ROOT_FOLDER_NAME "GPU Platformer" CACHE STRING "The name of the root install folder of the game.")



# ----- Adding all subprojects -----

add_subdirectory(parsers)
add_subdirectory(core)
add_subdirectory(launcher)
