#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    unsigned int selectedCar=0, selectedMap=0;

private slots:
    void on_select_car_clicked();

    void on_select_map_clicked();

    void on_start_game_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
