/********************************************************************************
** Form generated from reading UI file 'car.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAR_H
#define UI_CAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Car
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Car)
    {
        if (Car->objectName().isEmpty())
            Car->setObjectName(QStringLiteral("Car"));
        Car->resize(400, 300);
        menuBar = new QMenuBar(Car);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Car->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Car);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Car->addToolBar(mainToolBar);
        centralWidget = new QWidget(Car);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Car->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Car);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Car->setStatusBar(statusBar);

        retranslateUi(Car);

        QMetaObject::connectSlotsByName(Car);
    } // setupUi

    void retranslateUi(QMainWindow *Car)
    {
        Car->setWindowTitle(QApplication::translate("Car", "Car", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Car: public Ui_Car {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAR_H
