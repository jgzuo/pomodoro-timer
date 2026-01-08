#include "pomodoro_timer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PomodoroTimer timer;
    timer.show();

    return app.exec();
}
