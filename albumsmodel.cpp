#include "albumsmodel.h"

AlbumsModel::AlbumsModel(QObject *parent)
    : AbstractAlbumModel(parent)
{
    m_albumsManager = nullptr;
    m_cardsManager = nullptr;
}


AlbumsModel::AlbumsModel(AlbumsManager *albumsManager, QObject *parent)
    : AbstractAlbumModel(albumsManager, parent)
{
    this->m_albumsManager = albumsManager;
    connect(albumsManager, SIGNAL(albumAdded(int)), this, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(albumRemoved(int)), this, SLOT(onAlbumRemoved(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,int)), this, SLOT(onCardAdded(int, int)));
    connect(albumsManager, SIGNAL(cardRemoved(int,int)), this, SLOT(onCardRemoved(int, int)));
}

void AlbumsModel::setAlbumsManager(AlbumsManager *albumsManager)
{
    this->AbstractAlbumModel::setAlbumsManager(albumsManager);
    this->m_albumsManager = albumsManager;
}

void AlbumsModel::setCardsManager(CardsManager *cardsManager)
{
    this->m_cardsManager = cardsManager;
}


void AlbumsModel::showAlbums()
{
    beginResetModel();
    m_albums = m_albumsManager->getAlbumsSpec();
    endResetModel();
}

int AlbumsModel::rowCount(const QModelIndex &) const
{
    return this->m_albums.getAlbumIds().count();
}

Album AlbumsModel::albumForIndex(const QModelIndex &index) const
{
    return this->m_albumsManager->getAlbum(m_albums.getAlbumIds().at(index.row()).toInt());

}

void AlbumsModel::onAlbumAdded(const int &albumId)
{
    const Albums updatedAlbums = m_albumsManager->getAlbumsSpec();
    const int row = updatedAlbums.getAlbumIds().indexOf(QString::number(albumId));

    beginInsertRows(QModelIndex(), row, row);
    m_albums = updatedAlbums;
    endInsertRows();

    emit albumAdded(m_albums.getNrOfAlbums());
}

//// Receives a signal from the AlbumsManager when an Album is removed
//void AlbumsModel::onAlbumRemoved(const int &albumId)
//{
//    beginResetModel();
//    capacity = m_albumsManager->getNrOfAlbums();
//    this->m_albums = new Album*[capacity];
//    for (int i = 0; i < capacity; i++)
//    {
//        this->m_albums[i] = nullptr;
//    }
//    m_albumsManager->getAlbums(m_albums);
//    endResetModel();
//}

void AlbumsModel::onCardAdded(const int &albumId, const QString &cMID)
{
    beginResetModel();
    m_albums = m_albumsManager->getAlbumsSpec();
    endResetModel();
    emit albumAdded(m_albums.getNrOfAlbums());
}

//// Receives a signal from the AlbumsManager when a Card is removed from an Album
//void AlbumsModel::onCardRemoved(const int &albumId)
//{
//    beginResetModel();
//    capacity = m_albumsManager->getNrOfAlbums();
//    this->m_albums = new Album*[capacity];
//    for (int i = 0; i < capacity; i++)
//    {
//        this->m_albums[i] = nullptr;
//    }
//    m_albumsManager->getAlbums(m_albums);
//    endResetModel();
//}
