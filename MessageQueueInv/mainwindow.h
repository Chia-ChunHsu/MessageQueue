#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtbridge.h>
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
    void on_startUpButton_clicked();

    void UpdateSlot(int number);

private:
    Ui::MainWindow *ui;
    QtBridge *bridge;
};

#endif // MAINWINDOW_H
