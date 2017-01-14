#include "albumsmanager.h"
#include <iostream>

// Constructors & Destructor
AlbumsManager::AlbumsManager(QObject* parent) :QObject(parent)
{
    this->uniqueIds = 1000;
    this->cardsManager = nullptr;
}

int AlbumsManager::linearSearch(const int &id) const
{
    int pos = -1;
    for (int i = 0; i < this->albums.count() && pos == -1; i++) {
        if (this->albums[i].getId() == id)
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


Album AlbumsManager::getAlbum(int id) const
{
    int pos = this->linearSearch(id);
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
    return this->m_albums;
}


// Management
void AlbumsManager::addAlbum(const QString &name)
{
    uniqueIds++;
    Album newAlb(name,uniqueIds,cardsManager);
    albums << newAlb;
    m_albums.addAlbum(uniqueIds);
    emit albumAdded(uniqueIds);
}

void AlbumsManager::addCard(const int &id, const QString &cardId)
{
    int pos = this->linearSearch(id);
    if (pos == -1)
    {
        QString exc = "Album Id not found.";
        throw exc;
    }
    this->albums[pos].addCard(cardsManager->addCard(cardId));
    QString cMID = this->albums[pos].getCardMID(this->albums[pos].getNrOfCards()-1);
    emit cardAdded(id,cMID);
}

