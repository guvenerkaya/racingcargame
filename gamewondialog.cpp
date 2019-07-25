 #include "gamewondialog.h"
#include "ui_gamewondialog.h"
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>
#include<QDebug>

GameWonDialog::GameWonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWonDialog)
{
    QMediaPlayer * gamewonmusic= new QMediaPlayer();
    gamewonmusic->setMedia(QUrl("qrc:/soundEffects/Queen - We Are The Champions.mp3"));
    gamewonmusic->play();

    QMovie *movie = new QMovie(":/videoEffects/gamewon.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
    processLabel->setGeometry(0,0, 400,400);
    //ui->setupUi(this);




}

GameWonDialog::~GameWonDialog()
{
    delete ui;
}

