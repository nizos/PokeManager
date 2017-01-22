#ifndef CARDSSQLMANAGER_H
#define CARDSSQLMANAGER_H
#include "resourceimageprovider.h"
#include "card.h"
#include <QSqlDatabase>
#include <QNetworkAccessManager>
#include <QHash>
#include <QDateTime>
#include <QSignalMapper>
#include <QString>
#include <QObject>
#include <QSQl>


class CardsSQLManager : public QObject
{
    Q_OBJECT

public:
    CardsSQLManager(QObject* parent = 0);
    void setDB(QSqlDatabase* db);
    void setResourceImageProvider(ResourceImageProvider* resourceImageProvider);
    void addCard(int albID, QString crdReq);
    void removeCard(int albID, int crdID);

signals:
    void cardAdded(int albID, int crdID);
    void cardUpdated(int albID, int crdID);
    void cardRemoved(int albID, int crdID);
    void albumUpdated(int albID);
    void mapped(int albID, int crdID);

public slots:
//    void cardImageAdded(int albID, int crdID);
    void mappedReply(int crdID);

private:
    QSqlDatabase* db;
    QSignalMapper m_mapper;
    CardsSQLModel* cardsSQLModel;
    QNetworkAccessManager *manager;

    QHash<int, QNetworkReply*> m_replies;
    ResourceImageProvider* resourceImageProvider;
};

#endif // CARDSSQLMANAGER_H
