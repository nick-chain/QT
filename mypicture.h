#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QFileDialog>
#include  <QColor>
#include <QScrollArea>
#include <QLabel>
#define MaxSize 100

class mypicture : public QWidget
{
    Q_OBJECT

public:
    mypicture(QWidget *parent = 0);
      ~mypicture();

private slots:
    void show_picture();
    void show_left();
    void show_right();
private:
    QPushButton *btn_file, *left,*right;
    QTextEdit* tdt;
    QLabel* lab;
    QScrollArea* sa;
    QString str[100];
    int i;
    int count;

};

#endif // MYPICTURE_H
