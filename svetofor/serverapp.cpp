#include "serverapp.h"
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"


ServerApp::ServerApp(CommParams& comPars, int argc, char *argv[]) : QApplication(argc, argv) {
    com = new Communicator(comPars);

    if (com->isReady()) {
        connect(com, &Communicator::recieved, this, &ServerApp::processMsg);
        connect(this, &ServerApp::send, com, &Communicator::send);
    }
    interface = new MainWindow;
    connect(this, &ServerApp::displayAnswerSignal, interface, &MainWindow::displayAsnsweSlot);
    interface->show();

}

ServerApp::~ServerApp() {
    if (com != nullptr)
        delete com;
    if (interface != nullptr)
        delete interface;
}

void ServerApp::processMsg(QByteArray bytes) {
    QJsonDocument msg = QJsonDocument::fromJson(bytes);
    QJsonDocument resp;
    QJsonObject response;
    QString ans;

    response["option"] = msg["option"].toInt();
    response["t_avtomatich"] = msg["t_avtomatich"].toInt();


    switch (msg["option"].toInt()) {

    case 1:
    {

        response["message"] = QJsonValue("Жёлтый");
        ans += QString::number(response["option"].toInt()) + " " + response["message"].toString();
        emit displayAnswerSignal(ans);
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }

    case 2:

        {
            int timeInSeconds = msg["t_avtomatich"].toInt();
            response["message"] =QJsonValue(timeInSeconds);
            QString ans;
            ans += QString::number(response["option"].toInt()) + " " +
                   QString::number(timeInSeconds * 1000);

            emit displayAnswerSignal(ans);
            resp.setObject(response);
            emit send(resp.toJson());
            break;


        }

    case 3:
    {

        QString ans;

        QString colorName;
        switch (msg["vib"][0].toInt()) {
        case 1: colorName = "1"; break;
        case 2: colorName = "2"; break;
        case 3: colorName = "3"; break;

        }
        QString inxname;
        switch (msg["vib"][1].toInt()) {
        case 1: inxname= "1"; break;
        case 2: inxname = "2"; break;
        case 3: inxname = "3"; break;
        case 4: inxname = "4"; break;

        }
        response["message"] = QJsonValue(colorName);
        response["message2"] = QJsonValue(inxname);

        ans += QString::number(response["option"].toInt()) + " " +response["message"].toString() + " " +response["message2"].toString();

        emit displayAnswerSignal(ans);
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }

    default:
        response["message"] = QJsonValue("unsupported option");
        resp.setObject(response);
        emit send(resp.toJson());
        break;
    }


}



