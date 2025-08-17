#include <QTimer>
#include <QObject>
#include "traffictimer.h"


TrafficTimer::TrafficTimer(QObject* parent) : QObject(parent) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TrafficTimer::changeState);
}


TrafficTimer::~TrafficTimer() {
    delete timer;
}


void TrafficTimer::start(int interval) {
    timer->start(interval);
}


void TrafficTimer::stop() {
    timer->stop();
}

void TrafficTimer::changeState() {
    static int currentState = 0;
    currentState = (currentState + 1) % 4;
    emit stateChanged(currentState);
}
