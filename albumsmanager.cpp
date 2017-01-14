#include "albumsmanager.h"
#include <iostream>

// Constructors & Destructor
AlbumsManager::AlbumsManager(QObject* parent) :QObject(parent)
{
    this->albumMIDs = 1000;
    this->cardsManager = nullptr;
}

int AlbumsManager::linearSearch(const int &albumMID) const
{
    int pos = -1;
    for (int i = 0; i < this->albums.count() && pos == -1; i++) {
        if (this->albums[i].getAlbumMID() == albumMID)
        {
            pos = i;
        }
    }
    return pos;
}

// Setters
void AlbumsManager::setCardsManager(CardsManager *cardsManager)
{
    this->cardsManager = cardsManager;
}

// Getters
int AlbumsManager::getNrOfAlbums() const
{
    return this->albums.count();
}


Album AlbumsManager::getAlbum(int albumMID) const
{
    int pos = this->linearSearch(albumMID);
    if (pos == -1)
    {
        QString exc = "Album Id not found.";
        throw exc;
    }
    return this->albums[pos];
}

QList<Album> AlbumsManager::getAlbums()
{
    return this->albums;
}

Albums AlbumsManager::getAlbumsSpec()
{
    return this->albumsSpec;
}


// Management
void AlbumsManager::addAlbum(const QString &albumName)
{
    albumMIDs++;
    Album newAlb(albumName,albumMIDs,cardsManager);
    albums << newAlb;
    albumsSpec.addAlbum(albumMIDs);
    emit albumAdded(albumMIDs);
}

void AlbumsManager::addCard(const int &albumMID, const QString &cardReq)
{
    int pos = this->linearSearch(albumMID);
    if (pos == -1)
    {
        QString exc = "albumMID Id not found.";
        throw exc;
    }
    this->albums[pos].addCard(cardsManager->addCard(albumMID,cardReq));
    QString cardMID = this->albums[pos].getCardMID(this->albums[pos].getNrOfCards()-1);
    emit cardAdded(albumMID,cardMID);
}

