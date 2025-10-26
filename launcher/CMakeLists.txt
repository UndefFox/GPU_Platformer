cmake_minimum_required(VERSION 3.16)

project(launcher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(applauncher
    main.cpp
)

qt_add_qml_module(applauncher
    URI launcher
    VERSION 1.0
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(applauncher PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.applauncher
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(applauncher
    PRIVATE Qt6::Quick
)

install(TARGETS applauncher
    LIBRARY DESTINATION "${INSTALL_ROOT_FOLDER}/lib"
    RUNTIME DESTINATION "${INSTALL_ROOT_FOLDER}"
)
