#ifndef POMODORO_TIMER_H
#define POMODORO_TIMER_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QApplication>

class PomodoroTimer : public QMainWindow {
    Q_OBJECT

public:
    PomodoroTimer(QWidget *parent = nullptr);
    ~PomodoroTimer();

private slots:
    void startTimer();
    void pauseTimer();
    void resetTimer();
    void updateTimer();

private:
    void setupUI();
    void updateDisplay();
    void switchMode(bool workMode);

    // UI 组件
    QLabel *timeLabel;
    QLabel *modeLabel;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QProgressBar *progressBar;

    // 定时器
    QTimer *timer;

    // 时间设置（秒）
    static const int WORK_TIME = 25 * 60;      // 25分钟
    static const int BREAK_TIME = 5 * 60;      // 5分钟

    // 状态变量
    int remainingTime;
    int totalTime;
    bool isWorkMode;
    bool isRunning;
};

#endif // POMODORO_TIMER_H
