#ifndef MAINNETWORKMANAGER_H
#define MAINNETWORKMANAGER_H

#include<QObject>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>

class MainNetworkManager: public QObject
{
    Q_OBJECT
public:
    explicit MainNetworkManager(QObject *parent = 0);

    void makeRequest(QString endpointRequest);

signals:
    void readyData(QByteArray);
    void qnamFinished();

public slots:
    void readReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *qnam = new QNetworkAccessManager(this);
};

#endif // MAINNETWORKMANAGER_H
