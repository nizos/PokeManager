#ifndef CARDSSQLMANAGER_H
#define CARDSSQLMANAGER_H
#include "resourceimageprovider.h"
#include <QSqlDatabase>
#include "card.h"
#include <QObject>
#include <QSQl>


class CardsSQLManager : public QObject
{
    Q_OBJECT

public:
    CardsSQLManager();

    void addCard(QString cardReqId);
    void removeCard();

signals:
    void cardAdded(QString cardReqId);
    void cardUpdated(QString cardReqId);
    void mapped(QString cardReqId);

public slots:
    void mappedReply(QString cardReqId);

private:
    int cardMIDs;
    QSqlDatabase* db;
    QSignalMapper m_mapper;
    CardsSQLModel* cardsSQLModel;
    QNetworkAccessManager *manager;

    QHash<QString, QNetworkReply*> m_replies;
    ResourceImageProvider* resourceImageProvider;
};

#endif // CARDSSQLMANAGER_H
