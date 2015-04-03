#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <SDL2/SDL.h>
#undef main

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SDL_Joystick *joy;
    QTimer timer;
    int xAxis;
    int yAxis;
    int zAxis;
signals:
    void signalJoystick();
    void signalKeyboard();

private slots:
    void onTimer();
    void onJoystick();
};

#endif // MAINWINDOW_H
