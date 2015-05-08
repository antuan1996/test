#include <QCoreApplication>
#include "client.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client cl;
    return a.exec();
}
