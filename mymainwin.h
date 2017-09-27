#ifndef MYMAINWIN_H
#define MYMAINWIN_H

#include <QWidget>
#include "widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QIcon>
#include <QComboBox>
#include <QPixmap>
#include <QStringList>
#define MaxLen 100
class myMainwin : public QWidget
{
    Q_OBJECT
public:

    explicit myMainwin(QWidget *parent = nullptr);
private:
    Widget* wid;
    QPushButton* btn;
    QLineEdit *edt1,*edt2,*edt3,*edt4;
    QLabel *lab1,*lab2,*lab3,*lab4,*lab5;
    QComboBox *cbb;
    typedef struct{
       QString user_name[MaxLen],password[MaxLen];
    }user;
signals:

public slots:
    void show_window();
};

#endif // MYMAINWIN_H
