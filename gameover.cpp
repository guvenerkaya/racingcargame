#include "gameover.h"
#include "ui_gameover.h"
#include <QMovie>
#include <QLabel>
#include<QMediaPlayer>

gameOver::gameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    QMediaPlayer* gameoversound = new QMediaPlayer();
    gameoversound->setMedia(QUrl("qrc:/soundEffects/Funny-game-over-sound.mp3"));
    gameoversound->play();

    QMovie *movie = new QMovie(":/videoEffects/gameover.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
    processLabel->setGeometry(0,0,400,400);
    //ui->setupUi(this);
}

gameOver::~gameOver()
{
    delete ui;
}
