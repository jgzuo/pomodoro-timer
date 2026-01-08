cmake_minimum_required(VERSION 3.10)
project(PomodoroTimer)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理 Qt 的 MOC、UIC 和 RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 Qt5 库
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 添加可执行文件
add_executable(PomodoroTimer
    main.cpp
    pomodoro_timer.cpp
    pomodoro_timer.h
)

# 链接 Qt5 库
target_link_libraries(PomodoroTimer Qt5::Widgets)

# 设置输出目录
set_target_properties(PomodoroTimer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
