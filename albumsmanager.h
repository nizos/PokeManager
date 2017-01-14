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
    Albums m_albums;
    int uniqueIds;
    int linearSearch(const int &id) const;

public:
    // Constructors & Destructor
    explicit AlbumsManager(QObject* parent = 0);

    // Setters
    void setCardsManager(CardsManager *cardsManager);

    // Getters
    int getNrOfAlbums() const;
    Album getAlbum(int id) const;
    QList<Album> getAlbums();
    Albums getAlbumsSpec();

    // Management
    Q_INVOKABLE void addAlbum(const QString &name);
    Q_INVOKABLE void addCard(const int &albumId, const QString &cardId);

signals:
    // Signals
    void albumAdded(const int id);
    void cardAdded(const int albumId, const QString cMID);
};

#endif // ALBUMSMANAGER_H
