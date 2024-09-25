qt_add_executable(Kaizen
    main.cpp
    mainWindow.cpp

    widgets/todoWidget.cpp

    components/taskCard.cpp

    utils/databaseManager.cpp

    include/mainWindow.hpp
    include/todoWidget.hpp
    include/taskCard.hpp
    include/databaseManager.hpp
)

target_link_libraries(Kaizen PRIVATE Qt6::Widgets Qt6::Sql)

set_target_properties(Kaizen PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
