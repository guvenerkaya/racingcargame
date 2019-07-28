#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QDialog>

namespace Ui {
class gameOver;
}
///
/// \brief The gameOver class is derived from class QDialog to react the events of the car object.
///
class gameOver : public QDialog
{
    Q_OBJECT
public:
    ///
    /// \brief gameOver opens a game over gif and plays a game over sound.
    /// \param parent is QWidget which is inherited by QDialog.
    ///
    explicit gameOver(QWidget *parent = 0);
    ~gameOver();

private:
    Ui::gameOver *ui;
};

#endif // GAMEOVER_H
