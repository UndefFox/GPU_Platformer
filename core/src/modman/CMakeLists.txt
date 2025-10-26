add_library(modman OBJECT)
set_target_properties(modman PROPERTIES LINKER_LANGUAGE CXX)
target_sources(modman
    PRIVATE
        modman.cpp include/modman/modman.h
        module.cpp include/modman/module.h
        moduleinstance.cpp include/modman/moduleinstance.h
                           include/modman/api.h
)
target_include_directories(modman
    PRIVATE
        include/modman
    PUBLIC
        include
)
target_link_libraries(modman
    PUBLIC
        graphs
        parsers
)


