#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int color;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_radioButton_r_r_clicked();

    void on_radioButton_r_y_clicked();

    void on_radioButton_r_g_clicked();

private:
    Ui::MainWindow *ui;
    unsigned choice;

signals:
    void question(QByteArray);
public slots:


    void answer(QString);
};
#endif // MAINWINDOW_H
