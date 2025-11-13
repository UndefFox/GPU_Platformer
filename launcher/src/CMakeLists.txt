

qt_add_executable(applauncher main.cpp)
target_link_libraries(applauncher
    PRIVATE Qt6::Quick
)

qt_add_qml_module(CoreSingletone
    URI CoreSingletone
    VERSION 1.0
    SOURCES
        coresingletone.h
)






