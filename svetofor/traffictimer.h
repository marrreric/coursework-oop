#ifndef TRAFFICTIMER_H
#define TRAFFICTIMER_H

#include <QObject>
#include <QTimer>

class TrafficTimer : public QObject {
    Q_OBJECT

public:
    explicit TrafficTimer(QObject* parent = nullptr);
    ~TrafficTimer();
    void start(int interval);
    void stop();

signals:
    void stateChanged(int state);

private slots:
    void changeState();

private:
    QTimer* timer;
};

#endif // TRAFFICTIMER_H
