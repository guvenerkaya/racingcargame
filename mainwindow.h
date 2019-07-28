#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}
///
/// \brief The MainWindow class is used to make a simple game menu.
///
class MainWindow : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief MainWindow sets a backgrund picture and plays background music.
    /// \param parent is QWidget inherited by QDialog.
    ///
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ///
    /// \brief selectedCar is an integer value which specifies the car selection of the player,which he made  in MainWindow,
    /// selectedMap is an integer value which specifies the the map selection of the player,which he made in MainWindow
    ///
    unsigned int selectedCar=0, selectedMap=0;
    ///
    /// \brief themeSound is the background music to be set.
    ///
    QMediaPlayer* themeSound;

private slots:
    void on_select_car_clicked();

    void on_select_map_clicked();

    void on_start_game_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
