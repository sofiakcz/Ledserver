#include "ledserver.h"
#include "config.h"
#include <QDebug>

LedServer::LedServer(quint16 port, QObject *parent) : QObject(parent), m_port(port)
{
    m_gpio = new Gpio(this);
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &LedServer::myNewConnection);
}

void LedServer::start()
{
     m_server->listen(QHostAddress::Any, m_port);
}

// Client hat Verbindung zum Server aufgebaut
void LedServer::myNewConnection()
{
    qDebug() << "Bitte eine Zahl von 0 bis 15 eingeben: ";

    m_socket = m_server->nextPendingConnection();
    connect(m_socket, &QTcpSocket::readyRead, this, &LedServer::myServerRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &LedServer::myClientDisconnect);
}

// Client hat Verbindung zum Server getrennt
void LedServer::myClientDisconnect()
{
    qDebug() << "Verbindung getrennt";

    for (int a = 0; a < 4; a++) {
        m_gpio->set(LEDS[a], 0);
    }
    m_socket->close();
}

// Client hat eine Zahl (0...15) zum Server gesendet
void LedServer::myServerRead()
{
    while (m_socket->bytesAvailable()) {
       QString message = m_socket->readAll();
       int b = message.toInt();
       qDebug() << b;

       if (b >= 0 && b <= 15) {
           qDebug() << "OK";
           m_gpio->set(b);
       }
       qDebug() << "Bitte eine Zahl von 0 bis 15 eingeben: ";
   }
}
