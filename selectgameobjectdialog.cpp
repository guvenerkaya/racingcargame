#include "selectgameobjectdialog.h"
#include "ui_selectgameobjectdialog.h"

SelectGameObjectDialog::SelectGameObjectDialog(QWidget *parent,Selection s) :
    QDialog(parent),
    ui(new Ui::SelectGameObjectDialog)
{
    ui->setupUi(this);
    ui->backgroundGameObject->setPixmap(QPixmap(":/window_images/background.png"));
    switch (s)
        {
            case Car:
                ui->Decision_1->setPixmap(QPixmap(":/window_images/ferrari_forWind.png"));
                ui->Decision_2->setPixmap(QPixmap(":/window_images/mercedes_forWind.png"));
                ui->Decision_3->setPixmap(QPixmap(":/window_images/redbull_forWind.png"));
                break;

            case Map:
                ui->Decision_1->setPixmap(QPixmap(":/map_images/map2.png"));
                ui->Decision_2->setPixmap(QPixmap(":/map_images/map2.png"));
                ui->Decision_3->setPixmap(QPixmap(":/map_images/map2.png"));
                break;
        }


}

SelectGameObjectDialog::~SelectGameObjectDialog()
{
    delete ui;
}


void SelectGameObjectDialog::on_select_1_toggled(bool checked)
{
    if(checked)
            selectedFrame = 0;


}

void SelectGameObjectDialog::on_select_2_toggled(bool checked)
{
    if(checked)
            selectedFrame = 1;

}

void SelectGameObjectDialog::on_select_3_toggled(bool checked)
{
    if(checked)
            selectedFrame = 2;

}
unsigned int SelectGameObjectDialog::getSelected()
{
    return selectedFrame;
}

