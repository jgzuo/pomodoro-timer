# 🍅 番茄时钟 - Pomodoro Timer

一个使用 C++ 和 Qt 框架开发的现代化番茄工作法计时器应用程序，帮助您提高工作效率，保持良好的工作节奏。

![C++](https://img.shields.io/badge/C++-11-blue.svg)
![Qt](https://img.shields.io/badge/Qt-5.12+-41CD52.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

## ✨ 功能特性

### 核心功能
- ⏱️ **25分钟工作时间** - 基于番茄工作法的标准工作时长
- ☕ **5分钟休息时间** - 短暂休息，保持高效
- ⏯️ **完整控制** - 开始/暂停/重置功能
- 📊 **进度显示** - 直观的进度条和时间显示
- 🔄 **自动切换** - 工作和休息模式自动切换
- 🔔 **结束提醒** - 时间结束时弹出提示

### 界面设计
- 🎨 **现代化UI** - 精美的渐变色按钮和进度条
- 🎯 **模式标识** - 工作模式（红色）和休息模式（绿色）
- 📱 **简洁布局** - 清晰的信息层次
- ✨ **流畅动画** - 按钮悬停和点击效果

## 📸 界面预览

```
┌─────────────────────────────────┐
│         🍅 番茄时钟              │
├─────────────────────────────────┤
│                                 │
│         ⚪ 工作时间              │
│                                 │
│          🕐 25:00               │
│                                 │
│   ▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░    │
│                                 │
│    [▶开始]  [⏸暂停]  [↺重置]   │
│                                 │
│   💼 25分钟工作 · ☕ 5分钟休息   │
│                                 │
└─────────────────────────────────┘
```

## 🛠️ 技术栈

- **C++11** - 核心逻辑实现
- **Qt 5.12+** - 跨平台GUI框架
  - `QMainWindow` - 主窗口框架
  - `QTimer` - 定时器功能
  - `QProgressBar` - 进度条显示
  - `QLabel` - 文本和图标显示
  - `QPushButton` - 交互按钮
- **CMake** - 跨平台构建系统
- **qmake** - Qt 项目构建工具

## 📋 系统要求

### 最低要求
- **编译器**: 支持 C++11 的编译器
  - GCC 4.8+ (Linux)
  - MSVC 2015+ (Windows)
  - Clang 3.3+ (macOS)
- **Qt 版本**: Qt 5.12 或更高
- **CMake**: 3.10 或更高（使用 CMake 构建）
- **qmake**: Qt 5 自带（使用 qmake 构建）

### 推荐配置
- **Qt 版本**: Qt 5.15 或 Qt 6.x
- **编译器**: 支持 C++17 的编译器
- **RAM**: 512MB
- **磁盘空间**: 100MB

## 🚀 安装和运行

### 方法 1: 使用 CMake（推荐）

#### Linux/macOS

```bash
# 1. 克隆仓库
git clone https://github.com/jgzuo/pomodoro-timer.git
cd pomodoro-timer

# 2. 创建构建目录
mkdir build && cd build

# 3. 生成构建文件
cmake ..

# 4. 编译
cmake --build .

# 5. 运行
./PomodoroTimer
```

#### Windows

```cmd
# 1. 克隆仓库
git clone https://github.com/jgzuo/pomodoro-timer.git
cd pomodoro-timer

# 2. 创建构建目录
mkdir build
cd build

# 3. 生成 Visual Studio 项目
cmake ..

# 4. 编译
cmake --build . --config Release

# 5. 运行
Release\PomodoroTimer.exe
```

### 方法 2: 使用 qmake

#### Linux/macOS

```bash
# 1. 生成 Makefile
qmake PomodoroTimer.pro

# 2. 编译
make

# 3. 运行
./PomodoroTimer
```

#### Windows

```cmd
# 1. 生成 Makefile
qmake PomodoroTimer.pro

# 2. 编译
nmake

# 或使用 mingw32-make
mingw32-make

# 3. 运行
PomodoroTimer.exe
```

### 方法 3: 使用 Qt Creator

1. 打开 Qt Creator
2. 选择 **文件 → 打开文件或项目**
3. 选择 `PomodoroTimer.pro` 文件
4. 配置构建套件（Kit）
5. 点击左下角的**运行**按钮（绿色三角形）

## 📖 使用指南

### 基本操作

1. **启动程序**
   - 运行编译后的可执行文件
   - 程序启动后默认显示工作模式，倒计时 25 分钟

2. **开始工作**
   - 点击 **"开始"** 按钮启动倒计时
   - 进度条会随时间递减
   - 按钮状态会更新（开始禁用，暂停启用）

3. **暂停计时**
   - 点击 **"暂停"** 按钮暂停当前计时
   - 时间显示会停止更新
   - 可以点击"开始"继续

4. **重置计时**
   - 点击 **"重置"** 按钮重新开始
   - 计时器会重置到初始状态
   - 进度条恢复满格

5. **自动切换**
   - 工作时间（25分钟）结束后会弹出提示
   - 自动切换到休息模式（5分钟）
   - 休息结束后同样会提示并切换回工作模式

### 工作流程

```
开始 → 25分钟工作 → 📱提示 → 5分钟休息 → 📱提示 → 循环...
         ⬇️
      可暂停/重置
```

## 🎨 自定义配置

### 修改时间设置

如需自定义工作时长或休息时长，编辑 `pomodoro_timer.h` 文件：

```cpp
// 在 PomodoroTimer 类中修改这些常量
static const int WORK_TIME = 25 * 60;   // 工作时长（秒）
static const int BREAK_TIME = 5 * 60;   // 休息时长（秒）
```

**示例**：
```cpp
// 设置为 50分钟工作，10分钟休息
static const int WORK_TIME = 50 * 60;
static const int BREAK_TIME = 10 * 60;
```

### 修改界面样式

所有样式都在 `pomodoro_timer.cpp` 的 `setupUI()` 函数中定义：

**修改颜色方案**：
```cpp
// 工作模式标签颜色
modeLabel->setStyleSheet("QLabel { color: #e74c3c; }");

// 按钮颜色
startButton->setStyleSheet("QPushButton { background-color: #27ae60; }");
```

## 📁 项目结构

```
pomodoro-timer/
├── main.cpp                 # 程序入口
├── pomodoro_timer.h         # 番茄时钟类头文件
├── pomodoro_timer.cpp       # 番茄时钟类实现
├── CMakeLists.txt           # CMake 构建配置
├── PomodoroTimer.pro        # qmake 项目文件
├── BUILD_WINDOWS.md         # Windows 构建详细说明
└── README.md                # 项目说明文档
```

### 核心文件说明

| 文件 | 行数 | 说明 |
|------|------|------|
| `main.cpp` | ~10 | 应用程序入口，创建 QApplication 和主窗口 |
| `pomodoro_timer.h` | ~70 | PomodoroTimer 类声明，定义 UI 组件和成员变量 |
| `pomodoro_timer.cpp` | ~200 | PomodoroTimer 类实现，包含 UI 设置和计时逻辑 |

## 🔧 开发说明

### 类设计

```cpp
class PomodoroTimer : public QMainWindow {
    // 公共接口
public:
    PomodoroTimer(QWidget *parent = nullptr);
    ~PomodoroTimer();

private:
    // UI 组件
    QLabel *timeLabel;        // 时间显示
    QLabel *modeLabel;        // 模式标签
    QProgressBar *progressBar; // 进度条
    QPushButton *startButton; // 开始按钮
    QPushButton *pauseButton; // 暂停按钮
    QPushButton *resetButton; // 重置按钮

    // 成员变量
    QTimer *timer;            // 定时器
    int remainingTime;        // 剩余时间
    int totalTime;            // 总时间
    bool isWorkMode;          // 是否工作模式
    bool isRunning;           // 是否运行中

    // 私有方法
    void startTimer();        // 开始计时
    void pauseTimer();        // 暂停计时
    void resetTimer();        // 重置计时
    void updateTimer();       // 更新计时
    void switchMode(bool workMode); // 切换模式
};
```

### 关键方法

- **startTimer()** - 启动计时器，连接 timeout 信号
- **pauseTimer()** - 停止计时器，更新按钮状态
- **resetTimer()** - 重置所有状态到初始值
- **updateTimer()** - 每秒调用一次，更新显示和进度
- **switchMode()** - 在工作模式和休息模式之间切换

## 🐛 常见问题

### 编译问题

**Q: 找不到 Qt 头文件**
```
error: QMainWindow: No such file or directory
```

A: 确保 Qt 已正确安装并配置了环境变量：
```bash
# 检查 Qt 版本
qmake --version

# 设置 Qt 路径
export QT_HOME=/path/to/Qt/5.15/gcc_64
export PATH=$QT_HOME/bin:$PATH
```

**Q: CMake 找不到 Qt**
```
CMake Error: Could not find CMAKE_QT
```

A: 指定 Qt 的 CMAKE_PREFIX_PATH：
```bash
cmake -DCMAKE_PREFIX_PATH=/path/to/Qt/5.15/gcc_64 ..
```

### 运行问题

**Q: 程序启动后立即崩溃**

A: 确保 Qt 版本匹配，重新编译所有文件：
```bash
cmake --build . --clean-first
```

**Q: 按钮点击没有反应**

A: 检查信号槽连接是否正常，查看控制台错误信息。

## 🌟 特性详解

### 计时精度
- 使用 `QTimer` 实现 1 秒精度的倒计时
- 通过 `remainingTime` 变量精确跟踪剩余时间

### 状态管理
- `isRunning` 标志控制计时器状态
- `isWorkMode` 标志区分工作/休息模式
- 按钮状态动态更新（启用/禁用）

### 用户体验
- 大字体时间显示（48px）
- 清晰的进度条可视化
- 颜色区分模式（红色/绿色）
- 弹窗提示时间结束

## 📚 番茄工作法简介

番茄工作法（Pomodoro Technique）是一种时间管理方法：

1. 选择一个任务
2. 设定 25 分钟专注工作
3. 休息 5 分钟
4. 每 4 个番茄钟后长休息 15-30 分钟

**好处**：
- ✅ 减少拖延
- ✅ 提高专注力
- ✅ 保持工作节奏
- ✅ 避免过度疲劳

## 🔄 版本历史

### v1.0.0 (当前版本)
- ✅ 基础计时功能
- ✅ 工作和休息模式切换
- ✅ 进度条显示
- ✅ 开始/暂停/重置控制
- ✅ 跨平台支持（Windows/Linux/macOS）

## 🎯 未来计划

- [ ] 添加音效提醒
- [ ] 支持自定义时间
- [ ] 统计功能（完成的番茄钟数量）
- [ ] 系统托盘图标
- [ ] 主题切换（深色/浅色）
- [ ] 多语言支持
- [ ] 数据持久化
- [ ] 任务列表集成

## 🤝 贡献

欢迎贡献代码！请遵循以下步骤：

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

### 开发指南

- 遵循现有代码风格
- 添加必要的注释
- 测试新功能
- 更新文档

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件

## 👨‍💻 作者

Created with ❤️ by [jgzuo](https://github.com/jgzuo)

## 📮 联系方式

- GitHub: [@jgzuo](https://github.com/jgzuo)
- Issues: [提交问题](https://github.com/jgzuo/pomodoro-timer/issues)

## 🙏 致谢

- Qt 框架开发团队
- 番茄工作法的发明者 Francesco Cirillo
- 所有贡献者

---

**开始您的番茄工作之旅吧！** 🍅✨

*让每一分钟都更有价值*
