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

    int addCard(const QString id);
    int getNrOfCards() const;
    Card card(const QString cMID) const;
    QList<Card> cards() const;

signals:
    void cardAdded(const QString cMID);

public slots:
    void dataFromNetwork(const QByteArray data);

private:
    QList<Card> m_cards;
    int m_cardMID;
    MainNetworkManager m_networkManager;
    QByteArray m_data;
    int linearSearch(const QString cMID) const;
};

#endif // CARDSMANAGER_H
