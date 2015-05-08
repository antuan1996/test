#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QCoreApplication>
class client : public QObject
{
    Q_OBJECT
public:
    QTcpSocket * clsock;
     client();

signals:

public slots:
   void slotconnected();
   void sloterror(QAbstractSocket::SocketError);
};

#endif // CLIENT_H
