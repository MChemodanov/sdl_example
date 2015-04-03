#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_EVENTS);
    SDL_JoystickEventState(SDL_ENABLE);
    int result = SDL_NumJoysticks();

    joy = SDL_JoystickOpen(0);

    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    connect(this, SIGNAL(signalJoystick()), this, SLOT(onJoystick()));
    timer.setInterval(50);
    timer.start();
}

MainWindow::~MainWindow()
{
    SDL_Quit();
    delete ui;
}

void MainWindow::onTimer()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_JOYAXISMOTION:
                emit signalJoystick();
                break;
            default: break;
        }
    }
}

void MainWindow::onJoystick()
{
    xAxis = SDL_JoystickGetAxis(joy, 0);
    yAxis = SDL_JoystickGetAxis(joy, 1);
    zAxis = SDL_JoystickGetAxis(joy, 2);

    ui->pushButton->move(128+xAxis/256,128+yAxis/256);
    ui->pushButton->setText(QString::number(zAxis));
}
