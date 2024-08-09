qt_add_executable(Kaizen

    main.cpp
    mainWindow.cpp
    widgets/sideBar.cpp
    widgets/centralWidget.cpp
    widgets/todoWidget.cpp
    utils/styleManager.cpp
    utils/resizeFilter.cpp
    utils/dataManager.cpp
)

target_link_libraries(Kaizen PRIVATE Qt6::Widgets Qt6::Svg Qt6::Sql)

set_target_properties(Kaizen PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
