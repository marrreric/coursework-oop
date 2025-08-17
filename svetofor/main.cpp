#include "mainwindow.h"
#include <QHostAddress>
#include <QApplication>
#include "common.h"
#include "serverapp.h"
#include "mainwindow.h"
#include <QHostAddress>
#include <QApplication>
int main(int argc, char *argv[])
{


    CommParams pars = {QHostAddress::LocalHost, QHostAddress::LocalHost, 8080, 8081};

    ServerApp a(pars, argc, argv);
    return a.exec();
}
