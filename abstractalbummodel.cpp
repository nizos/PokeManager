#include "abstractalbummodel.h"

// Default Constructor
AbstractAlbumModel::AbstractAlbumModel(QObject* parent): QAbstractListModel(parent)
{
    m_albumsManager = nullptr;
}

// Overloaded Constructor
AbstractAlbumModel::AbstractAlbumModel(AlbumsManager *albumsManager, QObject *parent): QAbstractListModel(parent)
{
    this->m_albumsManager = albumsManager;
}

void AbstractAlbumModel::setAlbumsManager(AlbumsManager *albumsManager)
{
    this->m_albumsManager = albumsManager;
}

QVariant AbstractAlbumModel::data(const QModelIndex &index, int role)  const
{
    if (index.row() < 0 || index.row() > this->m_albumsManager->getNrOfAlbums())
        return QVariant();
    Album &album = albumForIndex(index);
    if (role == AlbumNameRole)
        return album.getAlbumName();
    else if (role == AlbumIDRole)
        return album.getAlbumMID();
    else if (role == CardsInAlbumRole)
        return album.getNrOfCards();
    else if (role == CardOneInAlbumRole)
        return album.getCardOneURL();
    else if (role == CardTwoInAlbumRole)
        return album.getCardTwoURL();
    else if (role == CardThreeInAlbumRole)
        return album.getCardThreeURL();
    else if (role == CardFourInAlbumRole)
        return album.getCardFourURL();
    return QVariant();
}

// Role names
QHash<int, QByteArray> AbstractAlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[AlbumNameRole] = "albumName";
    roles[AlbumIDRole] = "albumId";
    roles[CardsInAlbumRole] = "nrOfCards";
    roles[CardOneInAlbumRole] = "cardOneInAlbum";
    roles[CardTwoInAlbumRole] = "cardTwoInAlbum";
    roles[CardThreeInAlbumRole] = "cardThreeInAlbum";
    roles[CardFourInAlbumRole] = "cardFourInAlbum";
    return roles;
}
