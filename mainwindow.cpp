#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectgameobjectdialog.h"
#include <QMainWindow>
#include <QDebug>
#include "map.h"



MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BackGroundLabel->setPixmap(QPixmap(":/window_images/background.png"));

    themeSound=new QMediaPlayer();
    //play theme sound
    themeSound->setMedia(QUrl("qrc:/soundEffects/themeSong.mp3"));
    themeSound->play();
    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_car_clicked()
{
    //open car selection
    SelectGameObjectDialog SelectionWindow(this, Car);
        if(SelectionWindow.exec())
        {
            //get the selection
            this->selectedCar = SelectionWindow.getSelected();
        }
}

void MainWindow::on_select_map_clicked()
{
    //open map selection
    SelectGameObjectDialog SelectionWindow(this, Map);
        if(SelectionWindow.exec())
        {
            //get the selection
            this->selectedMap = SelectionWindow.getSelected();
        }

}

void MainWindow::on_start_game_clicked() //TODO
{
    //hide the main window dialog
    hide();

    // stop the playing music in the background
    themeSound->stop();

    //open the map scene with these selections
    map *startGame;
    //pass the selection to the map
    startGame=new map(this->selectedCar, this->selectedMap);
}
