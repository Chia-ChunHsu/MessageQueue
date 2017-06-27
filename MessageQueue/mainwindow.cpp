#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(!thread)
    {
        thread = new QThread(this);
        connect(thread,SIGNAL(sendMessage(QString)),ui->label,SLOT(setText(QString)));
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    if(!tWorks)
        tWorks = new threadWork();
    tWorks->start();
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<<tWorks->Size();
}
