#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), inputSocket{new QUdpSocket{}}, sendingSocket{new QUdpSocket{}}
{
    setupUi(this);
    connect(inputSocket, &QUdpSocket::readyRead, this, &MainWindow::onInputSignal);
    connect(sendMessageBtn, &QPushButton::clicked, this, &MainWindow::onSendBtnClicked);
    //connect(inputPortLineEdit, &QLineEdit::textChanged, this, &MainWindow::onInputPortChanged);
    //connect(remotePortLineEdit, &QLineEdit::textChanged, this, &MainWindow::onRemotePortChanged);
    connect(ConnectBtn, &QPushButton::clicked, this, &MainWindow::onInputPortChanged);
    connect(ConnectBtn, &QPushButton::clicked, this, &MainWindow::onRemotePortChanged);
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

void MainWindow::onInputPortChanged()
{
    inputPort = inputPortLineEdit->text().toInt();
    inputSocket->bind(inputPort);

}

void MainWindow::onRemotePortChanged()
{
    remotePort = remotePortLineEdit->text().toInt();
}


