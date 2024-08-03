qt_add_executable(Kaizen

    main.cpp
    mainWindow.cpp
    widgets/sideBar.cpp
    widgets/centralWidget.cpp
    utils/styleManager.cpp
)

target_link_libraries(Kaizen PRIVATE Qt6::Widgets Qt6::Svg)

set_target_properties(Kaizen PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
