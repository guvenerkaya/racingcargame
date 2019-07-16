/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_gameOver
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QDialog *gameOver)
    {
        if (gameOver->objectName().isEmpty())
            gameOver->setObjectName(QStringLiteral("gameOver"));
        gameOver->resize(800, 600);
        graphicsView = new QGraphicsView(gameOver);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setStyleSheet(QStringLiteral("background-image: url(:/window_images/game_over.jpg);"));

        retranslateUi(gameOver);

        QMetaObject::connectSlotsByName(gameOver);
    } // setupUi

    void retranslateUi(QDialog *gameOver)
    {
        gameOver->setWindowTitle(QApplication::translate("gameOver", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameOver: public Ui_gameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
