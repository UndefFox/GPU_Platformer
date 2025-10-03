add_library(modman STATIC)
set_target_properties(modman PROPERTIES LINKER_LANGUAGE CXX)
target_sources(modman
    PRIVATE
        modman.cpp include/modman/modman.h
        module.cpp include/modman/module.h
                   include/modman/moduleinterface.h
)
target_include_directories(modman
    PRIVATE
        include/modman
    PUBLIC
        include
)


