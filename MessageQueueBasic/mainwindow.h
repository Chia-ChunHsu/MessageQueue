#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wqueue.h>
#include <consumerthread.h>
#include <workitem.h>
#include <Windows.h>
#include <qtcthread.h>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    wqueue<WorkItem> queue;
    QtCThread *thread = 0;
    QTimer *timer = 0;
};

#endif // MAINWINDOW_H

