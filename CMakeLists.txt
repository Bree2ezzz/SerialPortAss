cmake_minimum_required(VERSION 3.16)

project(SerialPortAssQml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick QuickControls2 SerialPort Concurrent)

qt_standard_project_setup()

qt_add_executable(appSerialPortAssQml
    main.cpp
)

qt_add_qml_module(appSerialPortAssQml
    URI SerialPortAssQml
    VERSION 1.0
    QML_FILES
        Main.qml
        BlackBGBtn.qml
        ToggleTextButton.qml
        TransparentBtn.qml
        AutoSendDialog.qml
        PortSelectionDialog.qml
    SOURCES
        # ViewModels
        serialportviewmodel.h serialportviewmodel.cpp

        # Managers and Services
        serialportmanager.h serialportmanager.cpp
        dataprocessor.h dataprocessor.cpp
        logmanager.h logmanager.cpp
        portsettingsmanager.h portsettingsmanager.cpp

        # Strategies
        IWriteStrategy.h
        fullduplexwritestrategy.h fullduplexwritestrategy.cpp
        halfduplexwritestrategy.h halfduplexwritestrategy.cpp

        # Data Models
        LogEntry.h
        loglistmodel.h loglistmodel.cpp
        filesender.h filesender.cpp
)

# 将图片和字体以资源方式打包，提供明确的前缀，便于用 qrc:/icon/ 与 qrc:/font/ 访问
qt_add_resources(appSerialPortAssQml app_icons
    PREFIX "/icon"
    FILES
        test.jpg
        up.png
        upload.png
        down.png
        bidirection.png
        clear1.png
        clear2.png
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSerialPortAssQml PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSerialPortAssQml
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSerialPortAssQml
    PRIVATE Qt6::Quick
    Qt6::QuickControls2
    Qt6::SerialPort
    Qt6::Concurrent
)

include(GNUInstallDirs)
install(TARGETS appSerialPortAssQml
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
