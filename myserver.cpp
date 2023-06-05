#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer();

    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 4444))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("hello client ");
    socket->flush();

    socket->waitForBytesWritten(3000);

   // socket->close();
}
