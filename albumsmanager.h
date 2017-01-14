#ifndef ALBUMSMANAGER_H
#define ALBUMSMANAGER_H
#include "albums.h"
#include "album.h"
#include "card.h"
#include "cardsmanager.h"
#include <QObject>
#include <QDebug>

class AlbumsManager: public QObject
{
    Q_OBJECT

private:
    CardsManager *cardsManager;
    QList<Album> albums;
    Albums albumsSpec;
    int albumMIDs;
    int linearSearch(const int &albumMID) const;

public:
    // Constructors & Destructor
    explicit AlbumsManager(QObject* parent = 0);

    // Setters
    void setCardsManager(CardsManager* cardsManager);

    // Getters
    int getNrOfAlbums() const;
    Album getAlbum(int albumMID) const;
    QList<Album> getAlbums();
    Albums getAlbumsSpec();

    // Management
    Q_INVOKABLE void addAlbum(const QString &albumName);
    Q_INVOKABLE void addCard(const int &albumMID, const QString &cardReq);

signals:
    // Signals
    void albumAdded(const int albumMID);
    void cardAdded(const int albumMID, const QString cardMID);
};

#endif // ALBUMSMANAGER_H
