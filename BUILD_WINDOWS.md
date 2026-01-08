# 番茄时钟 - Windows 版本构建指南

本项目使用 GitHub Actions 自动构建 Windows 可执行文件。

## 🚀 快速开始（3 步获取 Windows EXE）

### 第 1 步：创建 GitHub 仓库

```bash
# 在项目目录初始化 git 仓库
cd /Users/zuojg/Downloads/Claude
git init

# 创建 .gitignore
cat > .gitignore << 'EOF'
build/
*.user
*.pro.user
.DS_Store
EOF

# 添加所有文件
git add .
git commit -m "Initial commit: Pomodoro Timer application"
```

### 第 2 步：推送到 GitHub

#### 2.1 在 GitHub 创建新仓库
1. 访问 https://github.com/new
2. 仓库名：`pomodoro-timer`（或自定义）
3. 设置为 **Public**（公开仓库可免费使用 Actions）
4. **不要**勾选 "Add a README file"
5. 点击 "Create repository"

#### 2.2 推送代码
```bash
# 添加远程仓库（替换 YOUR_USERNAME）
git remote add origin https://github.com/YOUR_USERNAME/pomodoro-timer.git

# 推送代码
git branch -M main
git push -u origin main
```

### 第 3 步：下载构建的 EXE

#### 3.1 触发构建
推送代码后，GitHub Actions 会自动开始构建。

#### 3.2 下载可执行文件
1. 访问你的仓库：`https://github.com/YOUR_USERNAME/pomodoro-timer`
2. 点击顶部的 **"Actions"** 标签
3. 点击左侧的 **"Build Windows EXE"**
4. 点击最新的构建任务（通常标记为 ✅ 或 ⚪）
5. 滚动到底部的 **"Artifacts"** 部分
6. 下载：
   - `PomodoroTimer-Windows-Portable` - 文件夹版本（解压即用）
   - `PomodoroTimer-Windows-ZIP` - ZIP 压缩包版本

## 📦 构建产物说明

### 下载后你会得到：
```
PomodoroTimer-Windows-Portable/
├── PomodoroTimer.exe       # 主程序（双击运行）
├── Qt5Core.dll             # Qt 核心库
├── Qt5Gui.dll              # Qt GUI 库
├── Qt5Widgets.dll          # Qt 组件库
├── platforms/              # 平台插件
│   └── qwindows.dll
└── styles/                 # 样式插件
    └── qwindowsvistastyle.dll
```

### 使用方法：
1. 解压下载的文件夹
2. **双击 `PomodoroTimer.exe` 即可运行**
3. 无需安装任何依赖

## 🔧 手动触发构建

如果想重新构建而不修改代码：

1. 访问仓库的 **Actions** 页面
2. 点击左侧的 **"Build Windows EXE"**
3. 点击右侧的 **"Run workflow"** 按钮
4. 选择分支（通常是 `main`）
5. 点击绿色的 **"Run workflow"** 按钮

## 📋 构建时间

- Windows 构建通常需要 **3-5 分钟**
- macOS 构建需要 **2-3 分钟**
- Linux 构建需要 **1-2 分钟**

## 🎯 使用多平台构建

如果想同时构建 Windows、macOS 和 Linux 版本：

启用 `.github/workflows/build.yml`：

```bash
# 重命名启用
mv .github/workflows/build.yml.disabled .github/workflows/build.yml
```

然后推送：
```bash
git add .github/workflows/
git commit -m "Enable multi-platform builds"
git push
```

## ⚙️ 构建配置详解

### Windows 工作流 (build-windows.yml)
- **操作系统**：Windows Server 2022
- **编译器**：MSVC 2019
- **Qt 版本**：5.15.2
- **构建工具**：CMake + windeployqt

### 支持的目标平台
- ✅ Windows 10/11 (64-bit)
- ✅ Windows Server 2016+
- ⚠️ Windows 7 可能需要额外安装更新

## 🐛 常见问题

### Q1: 构建失败怎么办？
- 检查 Actions 页面的错误日志
- 确保仓库是 **Public**（公开仓库）
- 确保代码已成功推送

### Q2: Windows Defender 报毒？
这是误报，因为：
- 程序未签名（自签名需要付费证书）
- 可以添加到排除列表

### Q3: EXE 无法运行？
- 确保下载了完整的 artifact
- 检查是否有杀毒软件拦截
- 确保解压了所有文件（包括 DLL 文件）

### Q4: 如何修改程序后重新构建？
1. 修改源代码
2. 提交并推送：
   ```bash
   git add .
   git commit -m "Update code"
   git push
   ```
3. GitHub Actions 会自动构建新版本

## 📝 发布版本（可选）

如果想创建正式发布版本：

```bash
# 创建标签
git tag v1.0.0
git push origin v1.0.0
```

GitHub Actions 会自动创建 Release 并附加构建产物。

## 🔗 有用的链接

- GitHub Actions 文档：https://docs.github.com/actions
- Qt 下载页面：https://www.qt.io/download
- CMake 文档：https://cmake.org/documentation

## 📧 反馈

如遇问题，请在 GitHub 仓库的 Issues 页面提交问题。
