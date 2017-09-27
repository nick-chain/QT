#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
/*this is QT 5.91 version about server code
 * that run only receive or send data from client
 * it keeps to TCP
 *what is most importance that server is able to
 *  send the data after receiving data.
 */
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void newConnect();
    void sendMessage(QString infomation);
    void readMessage();

private:
    Ui::Widget *ui;
    QString message;
    QString greeting;
    QString string;
    QTcpSocket *m_tcpsocket;
    QTcpServer *m_tcpserver;
    QList<QTcpSocket*> *socket_list;
};

#endif // WIDGET_H
