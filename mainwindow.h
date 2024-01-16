#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void pollMouse();

private slots:
    void startTest();

signals:
    void always_on();

private:
    Ui::MainWindow *ui;
    QTimer timerForPollMouse;
    QEventLoop poolMouseWaiting;
};
#endif // MAINWINDOW_H
