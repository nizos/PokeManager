#include "mainnetworkmanager.h"
#include<QDebug>

MainNetworkManager::MainNetworkManager(QObject *parent):
    QObject(parent)
{
    connect(qnam,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(readReply(QNetworkReply*)));
    connect(qnam,SIGNAL(finished(QNetworkReply*)),
            this,SIGNAL(qnamFinished()));
}

void MainNetworkManager::makeRequest(QString endpointRequest)
{
    qnam->get(QNetworkRequest(QUrl(endpointRequest)));
}

void MainNetworkManager::readReply(QNetworkReply *reply){
    QByteArray myData;
    myData = reply->readAll();
    emit(readyData(myData));
    reply->deleteLater();
}
