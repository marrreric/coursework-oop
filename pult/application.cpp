#include "application.h"

Application::Application(CommParams& pars, int argc, char *argv[],  QWidget* parent) : QApplication(argc, argv){
    com = new Communicator(pars);
    interface = new MainWindow;
    interface->show();
    connect(interface, &MainWindow::question, this, &Application::toCommunicator);
    connect(com, &Communicator::recieved, this, &Application::fromCommunicator);
    connect(this, &Application::displayAnswer, interface, &MainWindow::answer);
}

Application::~Application() {
    if (com != nullptr) delete com;
    if (interface != nullptr) delete interface;
}

void Application::fromCommunicator(QByteArray msg) {
    QString ans;
    QJsonDocument rcvd = QJsonDocument::fromJson(msg);
    ans += QString::number(rcvd["option"].toInt()) + " " + rcvd["message"].toString();
    emit displayAnswer(ans);
}

void Application::toCommunicator(QByteArray msg) {
    com->send(msg);
}
