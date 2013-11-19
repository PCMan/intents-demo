project(intents-demo)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(intents-demo_UIS intentsdialog.ui)
qt4_wrap_ui(intents-demo_UIS_H ${intents-demo_UIS})

set(intents-demo_SRCS intentsdialog.cpp main.cpp)
qt4_automoc(${intents-demo_SRCS})
add_executable(intents-demo ${intents-demo_SRCS} ${intents-demo_UIS_H})
target_link_libraries(intents-demo ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS intents-demo RUNTIME DESTINATION bin)
