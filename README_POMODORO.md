# 番茄时钟 (Pomodoro Timer)

一个使用 C++ 和 Qt 开发的简易番茄时钟应用程序。

## 功能特性

- ✅ **25分钟工作时间** - 专注工作，提高效率
- ✅ **5分钟休息时间** - 适当休息，保持状态
- ✅ **开始/暂停/重置** - 完整的定时器控制
- ✅ **进度条显示** - 直观查看时间进度
- ✅ **模式切换** - 工作模式（红色）和休息模式（绿色）
- ✅ **美观界面** - 现代化的 UI 设计
- ✅ **自动提醒** - 时间结束时弹出提示

## 界面预览

```
┌─────────────────────────────────┐
│         番茄时钟                 │
├─────────────────────────────────┤
│                                 │
│         工作时间                 │
│                                 │
│          25:00                  │
│                                 │
│   ▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░    │
│                                 │
│    [开始]  [暂停]  [重置]       │
│                                 │
│   25分钟工作 · 5分钟休息         │
│                                 │
└─────────────────────────────────┘
```

## 系统要求

- Qt 5.12 或更高版本
- CMake 3.10 或更高版本（使用 CMake 构建）
- qmake（使用 qmake 构建）
- C++11 或更高标准的编译器

## 编译和运行

### 方法 1：使用 CMake（推荐）

```bash
# 创建构建目录
mkdir build
cd build

# 生成 Makefile
cmake ..

# 编译
cmake --build .

# 运行
./bin/PomodoroTimer
```

### 方法 2：使用 qmake

```bash
# 生成 Makefile
qmake PomodoroTimer.pro

# 编译
make

# 运行
./PomodoroTimer
```

### Windows 平台

使用 CMake：
```cmd
mkdir build
cd build
cmake ..
cmake --build . --config Release
Release\PomodoroTimer.exe
```

使用 Qt Creator：
1. 打开 `PomodoroTimer.pro` 文件
2. 点击左下角的"运行"按钮

## 使用方法

1. **启动程序** - 运行编译后的可执行文件
2. **开始工作** - 点击"开始"按钮启动 25 分钟倒计时
3. **暂停计时** - 点击"暂停"按钮暂停当前计时
4. **重置计时** - 点击"重置"按钮重新开始
5. **自动切换** - 工作时间结束后自动切换到休息时间

## 工作流程

```
开始 → 25分钟工作 → 提示 → 5分钟休息 → 提示 → 循环...
```

## 文件说明

- `main.cpp` - 程序入口
- `pomodoro_timer.h` - 番茄时钟类头文件
- `pomodoro_timer.cpp` - 番茄时钟类实现
- `CMakeLists.txt` - CMake 构建配置
- `PomodoroTimer.pro` - qmake 项目文件

## 自定义设置

如需修改工作时间或休息时间，编辑 `pomodoro_timer.h`：

```cpp
static const int WORK_TIME = 25 * 60;  // 修改工作时长（秒）
static const int BREAK_TIME = 5 * 60;  // 修改休息时长（秒）
```

## 技术栈

- **C++11** - 核心逻辑
- **Qt Widgets** - GUI 框架
- **QTimer** - 定时器功能
- **QProgressBar** - 进度显示
- **CMake/qmake** - 构建系统

## 许可证

MIT License

## 作者

Created with Claude Code
