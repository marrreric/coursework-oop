#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QByteArray>
#include <QObject>
#include "common.h"
#include "mainwindow.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(CommParams& pars, int argc, char *argv[], QWidget* parent = nullptr);
    ~Application();
private:
    Communicator* com;
    MainWindow* interface;
public slots:
    void toCommunicator(QByteArray);
    void fromCommunicator(QByteArray);
signals:
    void displayAnswer(QString);
};

#endif // APPLICATION_H
