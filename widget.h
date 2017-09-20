#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QTimer>
#include <QLineEdit>
#include <QLCDNumber>
#include <QTime>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

          void paintEvent(QPaintEvent *){
          static int i = 0;
          static int j = 1;
          static int k = 1;
          static int m = 1;
          static int flag = 1;
          QTime time0 = QTime::currentTime();
          QPainter p(this);          //圆
          QPen pp(QColor(Qt::yellow));
          pp.setWidth(5);
          p.setPen(pp);
          p.translate(width()/2,height()/2);
          p.drawEllipse(QPoint( 0 , 0 ) , 200 , 200 );

          QPainter p1(this);           //秒
          QPen pp1(QColor(Qt::blue));
          pp1.setWidth(3);
          p1.setRenderHint(QPainter::Antialiasing);  //反锯齿函数
          p1.setPen(pp1);
          p1.translate(width()/2,height()/2);
          static int mse;
          if(flag){
              mse = time0.second();
              p1.rotate(mse*6);

          }
          else{
          p1.rotate(mse*6+3*i);
          }
          p1.drawLine(0,30,0,-130);
          i++;

          QPainter p2(this);            //分
          QPen pp2(QColor(Qt::green));
          pp2.setWidth(4);
          p2.setPen(pp2);
          p2.translate(width()/2,height()/2);
          static int min ;
          if(flag){
              min = time0.minute();
              p2.rotate(min*6+mse/60*6);
          }
          else{
          p2.rotate((min*6+mse/60*6)+3*j/60);
          }
          p2.setRenderHint(QPainter::Antialiasing);
          p2.drawLine(0,20,0,-100);
          j++;
               // QString text = time2.toString("hh:mm:ss");
          QPainter p3(this);             //时
          QPen pp3(QColor(Qt::yellow));
          pp3.setWidth(5);
          p3.setPen(pp3);
          p3.translate(width()/2,height()/2);
          static int h;
          if(flag){
              h = time0.hour();
              p3.rotate((h+min/60+mse/3600)%12*30);
              flag=0;
          }
          else{
          p3.rotate(((h+min/60+mse/3600)%12*30)+3*k/720);
          }

          p3.setRenderHint(QPainter::Antialiasing);
          p3.drawLine(0,10,0,-80);
          k++;

          QPainter p4(this);
          QPen pp4(QColor(Qt::yellow));
          pp4.setWidth(4);
          p4.translate(width()/2,height()/2);
          p4.setPen(pp4);
          for(m=1;m<=60;m++){
               p4.rotate(6);
               p4.drawPoint(0,-184);
          }

          QPainter p5(this);
          QPen pp5(QColor(Qt::yellow));
          pp5.setWidth(4);
          p5.translate(width()/2,height()/2);
          p5.setPen(pp5);
          for(m=1;m<=12;m++){
               p5.rotate(30);
               p5.drawLine(QPoint(0,184),QPoint(0,200));
          }

          QPainter p6(this);
          QPen pp6(QColor(Qt::blue));
          pp6.setWidth(20);
          p6.translate(width()/2,height()/2);
          p6.setPen(pp6);
          for(n=1;n<=12;n++)
          {
              p6.rotate(30);
              p6.drawText(0,-140,QString::number(n));
          }
}

private:
     QTimer *time;
     QTimer *time2;
     char n;
     int hour;
     int minute;
     int second;
     QString str;
     QLineEdit *led;
     QLCDNumber *lcd;
     QPushButton* btn;
  //   int flag;

private slots:
     void show_lcd();
};

#endif // WIDGET_H
