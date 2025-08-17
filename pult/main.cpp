#include "mainwindow.h"

#include <QApplication>
#include "application.h"
#include "common.h"

int main(int argc, char *argv[])
{
    CommParams pars{ QHostAddress::LocalHost, QHostAddress::LocalHost, 8081, 8080 };
    Application a(pars, argc, argv);
    return a.exec();
}

