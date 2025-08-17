#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui1(new Ui::MainWindow)
{
    ui1->setupUi(this);

    trafficTimer = new TrafficTimer(this);
    connect(trafficTimer, &TrafficTimer::stateChanged, this, &MainWindow::handleStateChanged);

}


MainWindow::~MainWindow() {
    delete ui1;
    delete trafficTimer;
}


void MainWindow::handleStateChanged(int state) {
    switch (state) {
    case 0:
        ui1->sv1->setText("ЖЕЛТЫЙ");
        ui1->sv2->setText("ЖЕЛТЫЙ");
        ui1->sv3->setText("ЖЕЛТЫЙ");
        ui1->sv4->setText("ЖЕЛТЫЙ");
        break;
    case 1:
        ui1->sv1->setText("ЗЕЛЕНЫЙ");
        ui1->sv2->setText("ЗЕЛЕНЫЙ");
        ui1->sv3->setText("ЗЕЛЕНЫЙ");
        ui1->sv4->setText("ЗЕЛЕНЫЙ");
        break;
    case 2:
        ui1->sv1->setText("ЖЕЛТЫЙ");
        ui1->sv2->setText("ЖЕЛТЫЙ");
        ui1->sv3->setText("ЖЕЛТЫЙ");
        ui1->sv4->setText("ЖЕЛТЫЙ");
        break;
    case 3:
        ui1->sv1->setText("КРАСНЫЙ");
        ui1->sv2->setText("КРАСНЫЙ");
        ui1->sv3->setText("КРАСНЫЙ");
        ui1->sv4->setText("КРАСНЫЙ");
        break;
    }

}

void MainWindow::displayAsnsweSlot(QString recieved) {
    QStringList data = {
        recieved.mid(0, recieved.indexOf(" ")),
        recieved.mid(recieved.indexOf(" ") + 1,
                     recieved.indexOf(" ", recieved.indexOf(" ") + 1) - (recieved.indexOf(" ") + 1)),
        recieved.mid(recieved.indexOf(" ", recieved.indexOf(" ") + 1) + 1)
    };

    int interval = 0;

    switch (data[0].toInt()) {
    case 1:
        trafficTimer->stop();
        ui1->sv1 -> setText(data[1]);
        ui1->sv2 -> setText(data[1]);
        ui1->sv3 -> setText(data[1]);
        ui1->sv4 -> setText(data[1]);

        break;
    case 2:
    {
        interval = data[1].toInt();
        trafficTimer->start(interval);
        break;

    }

    case 3:
    {
        trafficTimer->stop();
        if (data[2].toInt()==1){
            if(data[1].toInt()==1){
                ui1->sv1 -> setText("Красный");
            }
            if(data[1].toInt()==2){
                ui1->sv1 -> setText("Жёлтый");
            }
            if(data[1].toInt()==3){
                ui1->sv1 -> setText("Зелёный");
            }
        }
        if (data[2].toInt()==2){
            if(data[1].toInt()==1){
                ui1->sv2 -> setText("Красный");
            }
            if(data[1].toInt()==2){
                ui1->sv2 -> setText("Жёлтый");
            }
            if(data[1].toInt()==3){
                ui1->sv2 -> setText("Зелёный");
            }
        }
        if (data[2].toInt()==3){
            if(data[1].toInt()==1){
                ui1->sv3 -> setText("Красный");
            }
            if(data[1].toInt()==2){
                ui1->sv3 -> setText("Жёлтый");
            }
            if(data[1].toInt()==3){
                ui1->sv3 -> setText("Зелёный");
            }
        }
        if (data[2].toInt()==4){
            if(data[1].toInt()==1){
                ui1->sv4 -> setText("Красный");
            }
            if(data[1].toInt()==2){
                ui1->sv4 -> setText("Жёлтый");
            }
            if(data[1].toInt()==3){
                ui1->sv4 -> setText("Зелёный");
            }
        }

        break;

    }
    }

}











