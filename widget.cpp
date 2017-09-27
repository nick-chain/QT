#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(429,453);
    setWindowTitle("BugMe_Server");
    QFont font3;
    font3.setFamily(QString::fromUtf8("Tahoma"));
    font3.setPointSize(10);
    font3.setBold(true);
    font3.setWeight(60);
    ui->lineEdit->setFont(font3);
    ui->lineEdit ->setFont(font3);
    QPalette palette;
    palette=ui->textBrowser->palette();
    palette.setBrush(QPalette::Base, QBrush(Qt::NoBrush));
    ui->textBrowser->setPalette(palette);
    ui->lineEdit->setPalette(palette);
    m_tcpserver = new QTcpServer(this);
    m_tcpsocket = new QTcpSocket(this);
    socket_list = new QList<QTcpSocket*>;
    m_tcpserver->listen(QHostAddress::Any,8888);
    connect(m_tcpserver,SIGNAL(newConnection()),this,SLOT(newConnect()));
}

void Widget::newConnect()
{
    m_tcpsocket = m_tcpserver->nextPendingConnection();
    socket_list->append(m_tcpsocket);

    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(m_tcpsocket,SIGNAL(disconnected()),m_tcpsocket,SLOT(deleteLater()));
}
//receive the data from client
void Widget::readMessage()
{
    int i = 0;
    for(;i < socket_list->length();i ++)
    {
        QDataStream in(socket_list->at(i));
        in >> message;
        if(!(message.isEmpty()))
            break;
    }
    ui->textBrowser->append(tr("Client: %1").arg(message));
    sendMessage(message);
}
//send the data to object client
void Widget::sendMessage(QString infomation)
{
    QString str = infomation;
    QByteArray message;
    QDataStream out(&message,QIODevice::WriteOnly);
    out<<str;
    for (int i = 0;i < socket_list->length();i ++)
        socket_list->at(i)->write(message);
}

void Widget::on_pushButton_clicked()
{
    QString ser = "group";
    string = ser + "|" + ui->lineEdit->text() + "|" + "0";
    sendMessage(string);
    ui->lineEdit->clear();
}

Widget::~Widget()
{
    delete ui;
}
