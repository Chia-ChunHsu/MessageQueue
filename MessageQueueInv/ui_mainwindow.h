/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *addressLabel;
    QProgressBar *progressBar;
    QLabel *messageLabel;
    QLabel *messageLabel2;
    QProgressBar *progressBar2;
    QLabel *functionPointerLabel;
    QPushButton *startUpButton;
    QPushButton *startUpButton2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(393, 249);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addressLabel = new QLabel(centralWidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        gridLayout->addWidget(addressLabel, 1, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 3, 0, 1, 1);

        messageLabel = new QLabel(centralWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));

        gridLayout->addWidget(messageLabel, 2, 0, 1, 1);

        messageLabel2 = new QLabel(centralWidget);
        messageLabel2->setObjectName(QStringLiteral("messageLabel2"));

        gridLayout->addWidget(messageLabel2, 5, 0, 1, 1);

        progressBar2 = new QProgressBar(centralWidget);
        progressBar2->setObjectName(QStringLiteral("progressBar2"));
        progressBar2->setMaximum(100);
        progressBar2->setValue(0);

        gridLayout->addWidget(progressBar2, 6, 0, 1, 1);

        functionPointerLabel = new QLabel(centralWidget);
        functionPointerLabel->setObjectName(QStringLiteral("functionPointerLabel"));

        gridLayout->addWidget(functionPointerLabel, 4, 0, 1, 1);

        startUpButton = new QPushButton(centralWidget);
        startUpButton->setObjectName(QStringLiteral("startUpButton"));

        gridLayout->addWidget(startUpButton, 3, 1, 1, 1);

        startUpButton2 = new QPushButton(centralWidget);
        startUpButton2->setObjectName(QStringLiteral("startUpButton2"));

        gridLayout->addWidget(startUpButton2, 6, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 393, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addressLabel->setText(QApplication::translate("MainWindow", "Pass by Reference", Q_NULLPTR));
        messageLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        messageLabel2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        functionPointerLabel->setText(QApplication::translate("MainWindow", "Function Pointer", Q_NULLPTR));
        startUpButton->setText(QApplication::translate("MainWindow", "Start Up Sub Program", Q_NULLPTR));
        startUpButton2->setText(QApplication::translate("MainWindow", "Start Up Sub Program", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
