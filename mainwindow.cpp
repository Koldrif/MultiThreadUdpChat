#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), inputSocket{}, sendingSocket{}
{
    setupUi(this);
    connect(inputSocket, &QUdpSocket::readyRead, this, &MainWindow::onInputSignal);
    connect(sendMessageBtn, &QPushButton::clicked, this, &MainWindow::onSendBtnClicked);
    connect(inputPortLineEdit, &QLineEdit::textChanged, this, &MainWindow::onInputPortChanged);
    connect(remotePortLineEdit, &QLineEdit::textChanged, this, &MainWindow::onRemotePortChanged);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onInputSignal()
{
    if (inputSocket->hasPendingDatagrams())
    {
        QByteArray datagramm{inputSocket->pendingDatagramSize(), ' '};
        inputSocket->readDatagram(datagramm.data(), datagramm.size());
        chatTextField->append(datagramm.data());
    }
}

void MainWindow::onSendBtnClicked()
{
    if (!messageInput->text().size())
        return;
    QByteArray dataToSend{messageInput->text().toLocal8Bit()};
    sendingSocket->writeDatagram(dataToSend, remoteAddress, remotePort);
}

void MainWindow::onInputPortChanged(const QString &port)
{
    inputPort = port.toInt();
}

void MainWindow::onRemotePortChanged(const QString &port)
{
    remotePort = port.toInt();
}


