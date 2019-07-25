/********************************************************************************
** Form generated from reading UI file 'countdown.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWN_H
#define UI_COUNTDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_countDown
{
public:

    void setupUi(QDialog *countDown)
    {
        if (countDown->objectName().isEmpty())
            countDown->setObjectName(QStringLiteral("countDown"));
        countDown->resize(800, 600);

        retranslateUi(countDown);

        QMetaObject::connectSlotsByName(countDown);
    } // setupUi

    void retranslateUi(QDialog *countDown)
    {
        countDown->setWindowTitle(QApplication::translate("countDown", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class countDown: public Ui_countDown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWN_H
