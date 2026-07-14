add_executable(tictactoe
    main.cpp
    mainWindow.cpp
)

target_link_libraries(tictactoe PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(tictactoe PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)