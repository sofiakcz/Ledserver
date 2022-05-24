#include <QCoreApplication>
#include <QDebug>
#include "ledserver.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try {
        LedServer server(PORT);
        server.start();
        return a.exec();

    } catch (const char* msg) {
        qDebug() << msg;
        a.quit();
    }
}
