qt_add_executable(Kaizen
    main.cpp
)

target_link_libraries(Kaizen PRIVATE Qt6::Widgets)

set_target_properties(Kaizen PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
