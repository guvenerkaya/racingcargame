/********************************************************************************
** Form generated from reading UI file 'selectgameobjectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTGAMEOBJECTDIALOG_H
#define UI_SELECTGAMEOBJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SelectGameObjectDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *Decision_1;
    QLabel *Decision_2;
    QLabel *Decision_3;
    QRadioButton *select_1;
    QRadioButton *select_2;
    QRadioButton *select_3;
    QLabel *backgroundGameObject;

    void setupUi(QDialog *SelectGameObjectDialog)
    {
        if (SelectGameObjectDialog->objectName().isEmpty())
            SelectGameObjectDialog->setObjectName(QStringLiteral("SelectGameObjectDialog"));
        SelectGameObjectDialog->resize(800, 600);
        buttonBox = new QDialogButtonBox(SelectGameObjectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(710, 520, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Decision_1 = new QLabel(SelectGameObjectDialog);
        Decision_1->setObjectName(QStringLiteral("Decision_1"));
        Decision_1->setGeometry(QRect(10, 160, 200, 200));
        Decision_2 = new QLabel(SelectGameObjectDialog);
        Decision_2->setObjectName(QStringLiteral("Decision_2"));
        Decision_2->setGeometry(QRect(260, 160, 200, 200));
        Decision_3 = new QLabel(SelectGameObjectDialog);
        Decision_3->setObjectName(QStringLiteral("Decision_3"));
        Decision_3->setGeometry(QRect(480, 160, 200, 200));
        select_1 = new QRadioButton(SelectGameObjectDialog);
        select_1->setObjectName(QStringLiteral("select_1"));
        select_1->setGeometry(QRect(100, 390, 100, 20));
        select_2 = new QRadioButton(SelectGameObjectDialog);
        select_2->setObjectName(QStringLiteral("select_2"));
        select_2->setGeometry(QRect(350, 390, 100, 20));
        select_3 = new QRadioButton(SelectGameObjectDialog);
        select_3->setObjectName(QStringLiteral("select_3"));
        select_3->setGeometry(QRect(560, 390, 100, 20));
        backgroundGameObject = new QLabel(SelectGameObjectDialog);
        backgroundGameObject->setObjectName(QStringLiteral("backgroundGameObject"));
        backgroundGameObject->setGeometry(QRect(0, 0, 956, 645));
        backgroundGameObject->raise();
        buttonBox->raise();
        Decision_1->raise();
        Decision_2->raise();
        Decision_3->raise();
        select_1->raise();
        select_2->raise();
        select_3->raise();

        retranslateUi(SelectGameObjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectGameObjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectGameObjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectGameObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectGameObjectDialog)
    {
        SelectGameObjectDialog->setWindowTitle(QApplication::translate("SelectGameObjectDialog", "Dialog", nullptr));
        Decision_1->setText(QString());
        Decision_2->setText(QString());
        Decision_3->setText(QString());
        select_1->setText(QString());
        select_2->setText(QString());
        select_3->setText(QString());
        backgroundGameObject->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectGameObjectDialog: public Ui_SelectGameObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTGAMEOBJECTDIALOG_H
