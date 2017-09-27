#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include <QStringList>
#include <QPalette>
#include <QTime>
#include <QCursor>
#include <QFont>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void sendMessage();
    void readMessage();
    void tcpServerConnect();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *m_tcpsocket;
    QString user_id;

};

#endif // WIDGET_H
