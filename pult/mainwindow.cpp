#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    choice = 0;
    color = 0;
    ui->spinBox_avtomatich->setDisabled(true);
    ui->spinBox_avtomatich->setDisabled(true);
    ui->spinBox_ryka->setDisabled(true);
    ui->radioButton_r_g->setDisabled(true);
    ui->radioButton_r_y->setDisabled(true);
    ui->radioButton_r_r->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)
{


    switch(index)
    {
    case 1:
        this->choice=1;
        ui->spinBox_avtomatich->setDisabled(true);
        ui->spinBox_ryka->setDisabled(true);
        ui->radioButton_r_g->setDisabled(true);
        ui->radioButton_r_y->setDisabled(true);
        ui->radioButton_r_r->setDisabled(true);
        break;
    case 2:
        this->choice=2;
        ui->spinBox_avtomatich->setEnabled(true);
        ui->spinBox_ryka->setDisabled(true);
        ui->radioButton_r_g->setDisabled(true);
        ui->radioButton_r_y->setDisabled(true);
        ui->radioButton_r_r->setDisabled(true);

        break;
    case 3:
        this->choice=3;
        ui->spinBox_ryka->setEnabled(true);
        ui->spinBox_avtomatich->setDisabled(true);
        ui->radioButton_r_g->setEnabled(true);
        ui->radioButton_r_y->setEnabled(true);
        ui->radioButton_r_r->setEnabled(true);

        break;
    }
}
void MainWindow::on_radioButton_r_r_clicked()
{
    this->color = 1;

}

void MainWindow::on_radioButton_r_y_clicked()
{
    this->color = 2;

}

void MainWindow::on_radioButton_r_g_clicked()
{
    this->color = 3;
}

void MainWindow::on_pushButton_clicked()
{
    QJsonDocument msg;
    QJsonObject request;

    request["option"] = QJsonValue(int(choice));
    switch (choice) {
    case 1:
    {
        msg.setObject(request);
        emit question(msg.toJson());
        break;}
    case 2:
    {


        QJsonValue timeInSeconds = ui->spinBox_avtomatich->text().toInt();
        request["t_avtomatich"] = timeInSeconds;
        msg.setObject(request);
        emit question(msg.toJson());
        break;

    }

    case 3:
    {

        QJsonArray vibor = {color, ui->spinBox_ryka->text().toInt()};
        request["vib"] = vibor;
        msg.setObject(request);
        emit question(msg.toJson());
        break;}
    }
}


void MainWindow::answer(QString recieved) {
    QStringList data = {recieved.mid(0, recieved.indexOf(" ")), recieved.mid(recieved.indexOf(" ") + 1)};
    switch (data[0].toInt()) {
    case 3:
    case 5:

        break;
    case 1:
    case 2:
    case 4:
        ui->statusbar->showMessage("Успешно", 5000);
        break;
    default:
        ui->statusbar->showMessage("Ошибка", 5000);
    }
}










