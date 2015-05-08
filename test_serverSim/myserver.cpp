#include "myserver.h"
#include <QCoreApplication>
myserver::myserver() : QObject(0)
{
    acc=0;
    sum=0;
    serv = new QTcpServer(this);
    serv->listen(QHostAddress::Any,2323);
    puts("Server created");
    connect(serv,SIGNAL(newConnection()),this,SLOT(slotConnectionAdd()),Qt::QueuedConnection);
}
void myserver::slotConnectionAdd()
{
    QTcpSocket* nsock = serv->nextPendingConnection();
    puts("New connection");
    connect(nsock,SIGNAL(readyRead()),this,SLOT(slotRead()),Qt::QueuedConnection);
    connect(nsock,SIGNAL(disconnected()),nsock,SLOT(deleteLater()));
}

void myserver::slotRead()
{
    if(acc>=3) return;
    puts("Getting info");
    QTcpSocket* reason= (QTcpSocket*)(sender());

    while(reason->bytesAvailable()<sizeof(int32_t)) continue;

    QDataStream in(reason);
    int32_t box;
    in>>box;
    printf("I got int %d\n",box);

    sum+=box;
    ++acc;
    if(acc==3) closeconn();
}
void myserver::closeconn()
{
    printf("Result sum is %d\n",sum);
    serv->deleteLater();
    QCoreApplication::quit();
}
