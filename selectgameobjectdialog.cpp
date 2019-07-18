#include "selectgameobjectdialog.h"
#include "ui_selectgameobjectdialog.h"

SelectGameObjectDialog::SelectGameObjectDialog(QWidget *parent,Selection s) :
    QDialog(parent),
    ui(new Ui::SelectGameObjectDialog)
{
    ui->setupUi(this);

    //set background image of the car/ map selection window
    ui->backgroundGameObject->setPixmap(QPixmap(":/window_images/background.png"));

    switch (s)
        {
            //if select car window is open
            case Car:
            //set labels as these pixmaps
                ui->Decision_1->setPixmap(QPixmap(":/window_images/ferrari_forWind.png"));
                ui->Decision_2->setPixmap(QPixmap(":/window_images/mercedes_forWind.png"));
                ui->Decision_3->setPixmap(QPixmap(":/window_images/redbull_forWind.png"));
                break;
            //if select map window is open
            case Map:
            //set labels as these pixmaps
                ui->Decision_1->setPixmap(QPixmap(":/map_images/map2.png"));
                ui->Decision_2->setPixmap(QPixmap(":/map_images/map2sunum.png"));
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

