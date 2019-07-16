/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *BackGroundLabel;
    QPushButton *select_car;
    QPushButton *select_map;
    QPushButton *start_game;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        BackGroundLabel = new QLabel(MainWindow);
        BackGroundLabel->setObjectName(QStringLiteral("BackGroundLabel"));
        BackGroundLabel->setGeometry(QRect(0, 0, 956, 645));
        select_car = new QPushButton(MainWindow);
        select_car->setObjectName(QStringLiteral("select_car"));
        select_car->setGeometry(QRect(150, 430, 113, 32));
        select_map = new QPushButton(MainWindow);
        select_map->setObjectName(QStringLiteral("select_map"));
        select_map->setGeometry(QRect(370, 460, 113, 32));
        start_game = new QPushButton(MainWindow);
        start_game->setObjectName(QStringLiteral("start_game"));
        start_game->setGeometry(QRect(560, 430, 113, 32));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dialog", nullptr));
        BackGroundLabel->setText(QString());
        select_car->setText(QApplication::translate("MainWindow", "select car", nullptr));
        select_map->setText(QApplication::translate("MainWindow", "select map", nullptr));
        start_game->setText(QApplication::translate("MainWindow", "start game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
