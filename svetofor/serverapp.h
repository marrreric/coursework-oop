#ifndef SERVERAPP_H
#define SERVERAPP_H

#include "common.h"
#include <string>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>
#include <QJsonValue>
#include "mainwindow.h"


class ServerApp : public QApplication
{
    Q_OBJECT
    MainWindow* interface;
    Communicator* com;
public:
    ServerApp(CommParams& pars, int argc, char *argv[]);
    ~ServerApp();
signals:
    void send(QByteArray);

    void displayAnswerSignal(QString);
private slots:
    void processMsg(QByteArray);
};

#endif // SERVERAPP_H

