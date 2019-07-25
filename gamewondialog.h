#ifndef GAMEWONDIALOG_H
#define GAMEWONDIALOG_H


#include <QDialog>

namespace Ui {
class GameWonDialog;
}

class GameWonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameWonDialog(QWidget *parent = 0);
    ~GameWonDialog();

private:
    Ui::GameWonDialog *ui;
};

#endif // GAMEWONDIALOG_H
