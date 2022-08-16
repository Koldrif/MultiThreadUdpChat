#ifndef NETWORKINTERACTOR_H
#define NETWORKINTERACTOR_H

#include <QObject>
#include <QQueue>
#include <QByteArray>
#include <QUdpSocket>
#include <QtNetwork>

#include "mainwindow.h"


class NetworkInteractor : public QObject
{
    Q_OBJECT
public:
    explicit NetworkInteractor(MainWindow *parent);
    quint16 localPort;
    quint16 remotePort;

    QHostAddress remoteHost;


private:
    QQueue<QByteArray>* packagesToSend;
    QQueue<QByteArray>* packagesToCome;
    QUdpSocket* UdpSender;
    QUdpSocket* UdpGetter;


signals:

public slots:
    void onInputSignal();
    void onSendBtnClicked(const QString& message);
    void onConnectBtnPressed(const quint16& localPort,const quint16& remotePort);

};

#endif // NETWORKINTERACTOR_H
