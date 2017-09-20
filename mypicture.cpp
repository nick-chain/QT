#include "mypicture.h"

mypicture::mypicture(QWidget *parent)
    : QWidget(parent)
{

    //this->setFixedSize(640,480);
    i=0;
    count=0;
    lab = new QLabel(this);
    lab->setFixedSize(640,480);
    lab->setScaledContents(true);

    btn_file = new QPushButton("open file",this);
    left = new QPushButton("<<",this);
    right = new QPushButton(">>",this);

    sa = new QScrollArea(this);
    sa->setWidget(lab);

    QVBoxLayout* vbox = new QVBoxLayout;
    QHBoxLayout* hbox = new QHBoxLayout;

    hbox->addWidget(left);
    hbox->addWidget(btn_file);
    hbox->addWidget(right);

    vbox->addWidget(sa);
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(btn_file,SIGNAL(clicked()),this,SLOT(show_picture()));
    connect(left,SIGNAL(clicked()),this,SLOT(show_left()));
    connect(right,SIGNAL(clicked()),this,SLOT(show_right()));
}

void mypicture::show_picture(){
    mypicture::str[i] = QFileDialog::getOpenFileName(this,"open Image","/home",
    "Images (*.png *.xpm *.jpg)");
     lab->setPixmap(QPixmap(mypicture::str[i]));
     count=i;
     i++;
}

void mypicture::show_left(){
    if(i==0){
        i =count;
    }
    else{
        --i;
    }
        lab->setPixmap(QPixmap(str[i]));

}
void mypicture::show_right(){
    if(i==(count+1)){
        i=0;
    }
    else{
        ++i;
        if(i==(count+1)){
            i=0;
        }
    }
        lab->setPixmap(QPixmap(str[i]));
}
mypicture::~mypicture()
{

}
