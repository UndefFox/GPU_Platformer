add_library(graphs OBJECT)
set_target_properties(graphs PROPERTIES LINKER_LANGUAGE CXX)
target_sources(graphs
    PRIVATE
    include/graphs/directedacyclicgraph.hpp
)
target_include_directories(graphs
    PRIVATE
        include/graphs
    PUBLIC
        include
)


