#ifndef SELECTGAMEOBJECTDIALOG_H
#define SELECTGAMEOBJECTDIALOG_H

#include <QDialog>
enum Selection
{
    Car,
    Map
};

namespace Ui {
class SelectGameObjectDialog;
}

class SelectGameObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectGameObjectDialog(QWidget *parent = nullptr, Selection s=Car);
    ~SelectGameObjectDialog();
    unsigned int getSelected();



private slots:
    void on_select_1_toggled(bool checked);

    void on_select_2_toggled(bool checked);

    void on_select_3_toggled(bool checked);

private:
    unsigned int selectedFrame = 0;
    Ui::SelectGameObjectDialog *ui;
};

#endif // SELECTGAMEOBJECTDIALOG_H
