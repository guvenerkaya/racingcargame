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
///
/// \brief The Selection enum is an input parameter that defines if the drawing is a map or car
///
class SelectGameObjectDialog : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief SelectGameObjectDialog creates the dialog with a background image and loads map/car images according to s(s is explained belove)
    /// \param parent
    /// \param s loads the selection windows(map selection/car selection) according to player's pushed button(select car or select map) in mainwindow
    ///
    explicit SelectGameObjectDialog(QWidget *parent = nullptr, Selection s=Car);
    ~SelectGameObjectDialog();
    ///
    /// \brief getSelected returns selected frame( player's selection of car/ map)
    ///
    ///
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
