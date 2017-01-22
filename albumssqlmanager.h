#ifndef ALBUMSSQLMANAGER_H
#define ALBUMSSQLMANAGER_H
#include "cardssqlmanager.h"
#include "album.h"
#include <QSqlDatabase>
#include <QSQl>
class AlbumsSQLManager : public QObject
{
    Q_OBJECT
public:
    AlbumsSQLManager(QObject* parent = 0);
    void setDB(QSqlDatabase* db);
    void setCardsSQLManager(CardsSQLManager* cardsSQLManager);
    Q_INVOKABLE void addAlbum(QString albReq);
    Q_INVOKABLE void removeAlbum(int albID);
    Q_INVOKABLE void addCard(int albID, QString crdReq);
    Q_INVOKABLE void removeCard(int albID, int crdID);

    Q_INVOKABLE int getNrOfCards(int albID);
    Q_INVOKABLE int getNrOfAlbums();

signals:
    void albumAdded(int albID);
    void albumUpdated(int albID);
    void albumRemoved(int albID);
    void cardAdded(int albID, int crdID);
    void cardUpdated(int albID, int crdID);
    void cardRemoved(int albID, int crdID);

private:
    QSqlDatabase* db;
    CardsSQLManager *cardsSQLManager;
};

#endif // ALBUMSSQLMANAGER_H
