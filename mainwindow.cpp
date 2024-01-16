#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerForPollMouse.setInterval(50);
    connect(&timerForPollMouse,&QTimer::timeout,&poolMouseWaiting,&QEventLoop::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pollMouse()
{
    MainWindow::close();
    while(true)
    {
        QPoint mouseLoc =QCursor::pos();
        qDebug()<<mouseLoc.x()<<" "<<mouseLoc.y();
        timerForPollMouse.start();
        poolMouseWaiting.exec();
    }
}
void MainWindow::startTest()
{
    this->pollMouse();

}


