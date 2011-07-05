#include <QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    timeLeft = new QLabel;
    timeLeft->setText(" ");
    timeLeft->setFont(QFont("Verdana", 24));
    mainLayout->addWidget(timeLeft);

    poller = new QTimer(this);
    connect(poller, SIGNAL(timeout()), this, SLOT(updateInterface()));

    widget->setLayout(mainLayout);
    setWindowTitle(tr("Calendar"));
    poller->start(1000);
    /*
    1 = "Monday"
    2 = "Tuesday"
    3 = "Wednesday"
    4 = "Thursday"
    5 = "Friday"
    6 = "Saturday"
    7 = "Sunday"
    */
    //6 = "Saturday" onAir day, 23 - hh onAir time, 00 - mm onAir time, 3 - onAir hours length
    //cal = new calendar(6, 23, 00, 3);
    cal = new calendar(2, 22, 00, 1);
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateInterface()
{
    //timeLeft->setText(QDateTime().currentDateTime().date().longDayName(QDateTime().currentDateTime().date().dayOfWeek()) + " time left: " + QDateTime().addSecs( QDateTime().currentDateTime().secsTo(QDateTime(QDate(2011, 12, 25))) ).toString("dd hh:mm:ss"));
    timeLeft->setText(cal->timeLeft());
    //qDebug() << QString::number(cal->msecToOnAir());
    //timeLeft->setText("time left: " + QDateTime().addSecs( QDateTime().currentDateTime().secsTo(QDateTime().currentDateTime()) ).toString("dd hh:mm:ss"));
}
