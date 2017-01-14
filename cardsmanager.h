#ifndef CARDSMANAGER_H
#define CARDSMANAGER_H
#include <QObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QAbstractListModel>
#include <QEventLoop>
#include <qnetworkaccessmanager.h>
#include "mainnetworkmanager.h"
#include "card.h"

class CardsManager : public QObject
{
    Q_OBJECT

public:
    CardsManager(QObject* parent = 0);

    int addCard(const int &albumMID, const QString &cardReq);
    int getNrOfCards() const;
    Card getCard(const QString cardMID) const;
    QList<Card> getCards() const;

signals:
    void cardAdded(const int albumMID, const QString cardMID);
    void cardUpdated(const int albumMID, const QString cardMID);

public slots:
    void dataFromNetwork(const QByteArray data);

private:
    int cardMIDs;
    QList<Card> cards;
    MainNetworkManager networkManager;
    int linearSearch(const int cardMID) const;
};

#endif // CARDSMANAGER_H
