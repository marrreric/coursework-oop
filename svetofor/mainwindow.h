#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include <string>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>
#include <QJsonValue>

#include <QTimer>
#include <QTime>
#include "traffictimer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int greenTime;
    int yellowTime;
    int redTime;
    QTimer *timer;

    TrafficTimer *trafficTimer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui1;
private slots:

    void handleStateChanged(int state);

public slots:

    void displayAsnsweSlot(QString);
};
#endif // MAINWINDOW_H
