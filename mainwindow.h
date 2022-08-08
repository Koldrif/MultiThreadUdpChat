#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtNetwork/QUdpSocket>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QHostAddress remoteAddress = QHostAddress::LocalHost;

private:
    QUdpSocket* inputSocket;
    QUdpSocket* sendingSocket;
    qint32 remotePort;
    qint32 inputPort;

private slots:
    void onInputSignal();
    void onSendBtnClicked();
    void onInputPortChanged();
    void onRemotePortChanged();

};
#endif // MAINWINDOW_H
