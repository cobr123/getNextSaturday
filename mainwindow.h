#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "calendar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateInterface();
private:
    QLabel  *timeLeft;
    QTimer  *poller;
    calendar    *cal;
};

#endif // MAINWINDOW_H
