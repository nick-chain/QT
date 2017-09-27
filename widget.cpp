#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("BugMe");
    setFixedSize(594,427);
    ui->textBrowser_2->append("My Status:");
    ui->textBrowser_3->append("Friend Status:");
    QPalette palette;
    palette=ui->textBrowser->palette();
    palette.setBrush(QPalette::Base, QBrush(Qt::NoBrush));
    ui->textBrowser->setPalette(palette);
    ui->textBrowser_2->setPalette(palette);
    ui->textBrowser_3->setPalette(palette);
    ui->lineEdit->setPalette(palette);

    QFont font3;
    font3.setFamily(QString::fromUtf8("Tahoma"));
    font3.setPointSize(12);
    font3.setBold(true);
    font3.setWeight(60);
    ui->lineEdit->setFont(font3);
    font3.setPointSize(10);
    ui->textBrowser->setFont(font3);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::tcpServerConnect()
{
    m_tcpsocket = new QTcpSocket(this);
    m_tcpsocket->abort();
    m_tcpsocket->connectToHost(QHostAddress::LocalHost,8888);
    ui->textBrowser_2->append("status:online");
    ui->textBrowser_2->append(tr("%1 %2").arg("connect success!").
    arg((QTime::currentTime()).toString("hh:mm:ss")));
    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

void Widget::sendMessage()
{
     QString string = ui->le_rec->text() + "|" + ui->le_id->text() +
     "|" + ui->lineEdit->text();
     QByteArray message;
     QDataStream data(&message,QIODevice::WriteOnly);
     data<<string;
     ui->textBrowser->append(tr("%1 %2").arg(ui->le_rec->text()).
     arg((QTime::currentTime()).toString("hh:mm:ss")));
     ui->textBrowser->append(ui->lineEdit->text());
     ui->textBrowser->append("");
     m_tcpsocket->write(message);
     ui->lineEdit->clear();
}
void Widget::readMessage()
{
    QDataStream in(m_tcpsocket);
    QString greeting;
    in >> greeting;
    QStringList str = greeting.split("|");
    if(ui->le_id->text() == str[0]){
        ui->textBrowser->append(tr("%1 %2").arg(str[1]).
        arg((QTime::currentTime()).toString("hh:mm:ss")));
        ui->textBrowser->append(tr("%1").arg(str[2]));
        ui->textBrowser->append("");
        ui->textBrowser_3->append(tr("%1 %2").arg("ID:").arg(str[1]));
        ui->textBrowser_3->append("status:online");
    }
    if(str[0] == "group")
        ui->textBrowser->append(tr("server: %1").arg(str[1]));
    str.clear();
}
void Widget::on_pushButton_clicked()
{
    tcpServerConnect();
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->textBrowser->append("you must connect your friend ID or write something!");
    }
    sendMessage();
    ui->lineEdit->clear();
}
