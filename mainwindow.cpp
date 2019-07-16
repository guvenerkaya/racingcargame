#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectgameobjectdialog.h"
#include <QMainWindow>
#include <QDebug>
#include "map.h"
#include <QMediaPlayer>

QMediaPlayer* themeSound=new QMediaPlayer();

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BackGroundLabel->setPixmap(QPixmap(":/window_images/background.png"));


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
    SelectGameObjectDialog SelectionWindow(this, Car);
        if(SelectionWindow.exec())
        {
            //qDebug()<<SelectionWindow.getSelected();
            this->selectedCar = SelectionWindow.getSelected();

            // update map etc
        }

}

void MainWindow::on_select_map_clicked() //bunlari da degistir //boollari buraya yaz
{
    SelectGameObjectDialog SelectionWindow(this, Map);
        if(SelectionWindow.exec())
        {
            this->selectedMap = SelectionWindow.getSelected();
            // update map etc
        }

}

void MainWindow::on_start_game_clicked() //TODO
{
    hide();
    themeSound->stop();

    //secimlerin cemin map ve araba fonksiyonunu cagir
    map *startGame;
    startGame=new map(this->selectedCar, this->selectedMap);
    //startGame->show();

}
