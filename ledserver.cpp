#include "ledserver.h"

LedServer::LedServer(quint16 port, QObject *parent) : QObject(parent), m_port(port)
{

}

void LedServer::start()
{

}

// Client hat Verbindung zum Server aufgebaut
void LedServer::myNewConnection()
{

}

// Client hat Verbindung zum Server getrennt
void LedServer::myClientDisconnect()
{

}

// Client hat eine Zahl (0...15) zum Server gesendet
void LedServer::myServerRead()
{

}
