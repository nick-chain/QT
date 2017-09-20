#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton("System Time",this);
    btn->setGeometry(500,420,100,30);
    setFixedSize(640,480);
    lcd = new QLCDNumber(this);
    lcd->setFixedSize(200,60);
    lcd->setDigitCount(8);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    //QTime current_time =QTime::currentTime();
    lcd->display(QTime::currentTime().toString("hh:mm:ss"));

    time = new QTimer;
    time->start(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(update()));

    time2 = new QTimer();
    connect(time2,SIGNAL(timeout()),this,SLOT(show_lcd()));
    time2->start(1000);
  //  connect(btn,SIGNAL(clicked(bool)),this,SLOT(show_lcd()));

}

void Widget::show_lcd(){
    QTime time2 = QTime::currentTime();
    QString text = time2.toString("hh:mm:ss");
    lcd->display(text);
    //flag = 1;

}

Widget::~Widget()
{

}
