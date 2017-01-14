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
#include <QNetworkAccessManager>
#include <QHash>
#include <QSignalMapper>
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
    void mapped(QString cardMID);


public slots:
    void dataFromNetwork(QByteArray data);
    void mappedReply(QString);

private:
    int cardMIDs;
    QList<Card> cards;
    QNetworkAccessManager *m_nam;
    MainNetworkManager networkManager;
    QSignalMapper m_mapper;
    QHash<QString, QNetworkReply*> m_replies;
    int linearSearch(const int cardMID) const;
};

#endif // CARDSMANAGER_H
