#include "client.h"
client::client() : QObject(0)
{
    clsock= new QTcpSocket();
    puts("Socket created");
    connect(clsock,SIGNAL(connected()),this, SLOT(slotconnected()));
    connect(clsock,SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(sloterror(QAbstractSocket::SocketError)));
    clsock->connectToHost(QHostAddress::Any,2323);
    QCoreApplication::quit();
}
void client::slotconnected()
{
    puts("Connected!");

    int32_t buf;
    buf%=100;

    QByteArray box;
    QDataStream str(&box,QIODevice::WriteOnly);
    str<<buf;

    clsock->write(box);
    clsock->flush();
    puts("Sent");

    while(clsock->bytesToWrite());

    QCoreApplication::quit();
}
void client::sloterror(QAbstractSocket::SocketError)
{
    puts("Connection error");
    QCoreApplication::quit();
}
