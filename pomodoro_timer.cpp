#include "pomodoro_timer.h"
#include <QMessageBox>
#include <QFont>

PomodoroTimer::PomodoroTimer(QWidget *parent)
    : QMainWindow(parent), remainingTime(WORK_TIME), totalTime(WORK_TIME),
      isWorkMode(true), isRunning(false) {

    setupUI();

    // 创建定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PomodoroTimer::updateTimer);

    updateDisplay();
}

PomodoroTimer::~PomodoroTimer() {}

void PomodoroTimer::setupUI() {
    // 设置窗口
    setWindowTitle("番茄时钟");
    setFixedSize(400, 300);

    // 创建中心部件和布局
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // 模式标签
    modeLabel = new QLabel("工作时间", this);
    modeLabel->setAlignment(Qt::AlignCenter);
    modeLabel->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: #e74c3c; }");
    mainLayout->addWidget(modeLabel);

    // 时间显示标签
    timeLabel = new QLabel("25:00", this);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setStyleSheet("QLabel { font-size: 48px; font-weight: bold; color: #2c3e50; }");
    mainLayout->addWidget(timeLabel);

    // 进度条
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, WORK_TIME);
    progressBar->setValue(WORK_TIME);
    progressBar->setStyleSheet(
        "QProgressBar {"
        "   border: 2px solid #bdc3c7;"
        "   border-radius: 5px;"
        "   text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "   background-color: #3498db;"
        "}"
    );
    mainLayout->addWidget(progressBar);

    // 按钮布局
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // 开始按钮
    startButton = new QPushButton("开始", this);
    startButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #27ae60;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 14px;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover { background-color: #229954; }"
        "QPushButton:pressed { background-color: #1e8449; }"
    );
    connect(startButton, &QPushButton::clicked, this, &PomodoroTimer::startTimer);
    buttonLayout->addWidget(startButton);

    // 暂停按钮
    pauseButton = new QPushButton("暂停", this);
    pauseButton->setEnabled(false);
    pauseButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #f39c12;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 14px;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover { background-color: #e67e22; }"
        "QPushButton:pressed { background-color: #d68910; }"
        "QPushButton:disabled { background-color: #95a5a6; }"
    );
    connect(pauseButton, &QPushButton::clicked, this, &PomodoroTimer::pauseTimer);
    buttonLayout->addWidget(pauseButton);

    // 重置按钮
    resetButton = new QPushButton("重置", this);
    resetButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e74c3c;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 14px;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover { background-color: #c0392b; }"
        "QPushButton:pressed { background-color: #a93226; }"
    );
    connect(resetButton, &QPushButton::clicked, this, &PomodoroTimer::resetTimer);
    buttonLayout->addWidget(resetButton);

    mainLayout->addLayout(buttonLayout);

    // 添加提示标签
    QLabel *hintLabel = new QLabel("25分钟工作 · 5分钟休息", this);
    hintLabel->setAlignment(Qt::AlignCenter);
    hintLabel->setStyleSheet("QLabel { color: #7f8c8d; font-size: 12px; }");
    mainLayout->addWidget(hintLabel);

    setCentralWidget(centralWidget);
}

void PomodoroTimer::startTimer() {
    if (!isRunning) {
        timer->start(1000); // 每秒触发一次
        isRunning = true;
        startButton->setEnabled(false);
        pauseButton->setEnabled(true);
    }
}

void PomodoroTimer::pauseTimer() {
    if (isRunning) {
        timer->stop();
        isRunning = false;
        startButton->setEnabled(true);
        pauseButton->setEnabled(false);
    }
}

void PomodoroTimer::resetTimer() {
    timer->stop();
    isRunning = false;
    isWorkMode = true;
    remainingTime = WORK_TIME;
    totalTime = WORK_TIME;
    startButton->setEnabled(true);
    pauseButton->setEnabled(false);
    switchMode(true);
    updateDisplay();
}

void PomodoroTimer::updateTimer() {
    if (remainingTime > 0) {
        remainingTime--;
        updateDisplay();
    } else {
        // 时间到
        timer->stop();
        isRunning = false;
        startButton->setEnabled(true);
        pauseButton->setEnabled(false);

        // 显示提示
        QString message = isWorkMode ? "工作时间结束！该休息一下了！" : "休息时间结束！继续工作吧！";
        QMessageBox::information(this, "提示", message);

        // 切换模式
        switchMode(!isWorkMode);
    }
}

void PomodoroTimer::updateDisplay() {
    // 计算分钟和秒
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    // 更新时间显示
    timeLabel->setText(QString("%1:%2")
        .arg(minutes)
        .arg(seconds, 2, 10, QChar('0')));

    // 更新进度条
    progressBar->setValue(totalTime - remainingTime);
}

void PomodoroTimer::switchMode(bool workMode) {
    isWorkMode = workMode;

    if (workMode) {
        modeLabel->setText("工作时间");
        modeLabel->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: #e74c3c; }");
        remainingTime = WORK_TIME;
        totalTime = WORK_TIME;
        progressBar->setRange(0, WORK_TIME);
        progressBar->setStyleSheet(
            "QProgressBar {"
            "   border: 2px solid #bdc3c7;"
            "   border-radius: 5px;"
            "   text-align: center;"
            "}"
            "QProgressBar::chunk {"
            "   background-color: #3498db;"
            "}"
        );
    } else {
        modeLabel->setText("休息时间");
        modeLabel->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: #27ae60; }");
        remainingTime = BREAK_TIME;
        totalTime = BREAK_TIME;
        progressBar->setRange(0, BREAK_TIME);
        progressBar->setStyleSheet(
            "QProgressBar {"
            "   border: 2px solid #bdc3c7;"
            "   border-radius: 5px;"
            "   text-align: center;"
            "}"
            "QProgressBar::chunk {"
            "   background-color: #2ecc71;"
            "}"
        );
    }

    updateDisplay();
}
