#include "mymainwin.h"

myMainwin::myMainwin(QWidget *parent) : QWidget(parent)
{

    setFixedSize(435,320);
    setWindowTitle("BugMe");
    QPixmap pix;
    pix.load("./github.png");
    btn = new QPushButton("sign in",this);
    edt1 = new QLineEdit(this);
   // cbb = new QComboBox(this);
    edt2 = new QLineEdit(this);
    edt3  =new QLineEdit(this);
    edt4  =new QLineEdit(this);
    edt1->setFixedWidth(150);
    edt2->setFixedWidth(150);
    edt3->setFixedSize(18,18);
    edt4->setFixedSize(18,18);
    btn->setFixedWidth(120);
    lab1 = new QLabel("UserName");
    lab2 = new QLabel("Password");
    lab3 = new QLabel(this);
    lab3->setPixmap(pix);
    lab4 = new QLabel("Save");
    lab4->setFixedWidth(50);
    lab5 = new QLabel("Automatic");


    QVBoxLayout* vbox = new QVBoxLayout;
    QHBoxLayout* hbox1 = new QHBoxLayout;
    QHBoxLayout* hbox2 = new QHBoxLayout;
    QHBoxLayout* hbox3 = new QHBoxLayout;
    QHBoxLayout* hbox4 = new QHBoxLayout;
    hbox4->addWidget(edt3);
    hbox4->addWidget(lab4);
    hbox4->addWidget(edt4);
    hbox4->addWidget(lab5);

    hbox1->addWidget(edt1);
    hbox1->addWidget(lab1);
    hbox1->setContentsMargins(0,80,0,0);
    hbox2->addWidget(edt2);
    hbox2->addWidget(lab2);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox4);
    vbox->addWidget(btn);
    vbox->setContentsMargins(0,0,0,50);
    hbox3->addWidget(lab3);
    hbox3->addLayout(vbox);
    setLayout(hbox3);
   /* QMovie*movie=new QMovie(fileName);
        ui.label->setMovie(movie);
        movie->start();*/
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(show_window()));
}

void myMainwin::show_window(){
    wid = new Widget;
    user userdata;
   // userdata.user_name[];
    wid->show();
    this->hide();



}
