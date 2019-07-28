#ifndef GAMEWONDIALOG_H
#define GAMEWONDIALOG_H


#include <QDialog>

namespace Ui {
class GameWonDialog;
}
///
/// \brief The GameWonDialog class is derived from class QDialog to react the events of the car object.
///
class GameWonDialog : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief GameWonDialog opens a gif saved gif and plays music.
    /// \param parent is QWidget which is inherited by QDialog.
    ///
    explicit GameWonDialog(QWidget *parent = 0);
    ~GameWonDialog();

private:
    Ui::GameWonDialog *ui;
};

#endif // GAMEWONDIALOG_H
