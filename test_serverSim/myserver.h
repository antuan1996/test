#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <cstdio>
class myserver : public QObject
{
    Q_OBJECT

public:
    int acc;
    int32_t sum;
    QTcpServer* serv;
    myserver();
    void closeconn();
    public slots:
       void slotConnectionAdd();
       void slotRead();
};

#endif // MYSERVER_H
