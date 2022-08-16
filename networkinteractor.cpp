#include "networkinteractor.h"

NetworkInteractor::NetworkInteractor(MainWindow *parent) :
    QObject(parent),
    packagesToSend{new QQueue<QByteArray>{}},
    packagesToCome{new QQueue<QByteArray>{}},
    localPort{},
    remotePort{}
{

}
