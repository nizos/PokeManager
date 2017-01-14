#include "albumcardsmodel.h"
AlbumCardsModel::AlbumCardsModel(QObject *parent)
    : AbstractCardModel(parent)
{
    m_albumsManager = nullptr;
    m_cardsManager = nullptr;
}

AlbumCardsModel::AlbumCardsModel(AlbumsManager *albumsManager, CardsManager *cardsManager, QObject *parent)
    : AbstractCardModel(cardsManager, parent)
{
    this->m_albumsManager = albumsManager;
    this->m_cardsManager = cardsManager;

    connect(m_albumsManager, SIGNAL(albumAdded(int)),
            this, SLOT(onAlbumAdded(int)));
    connect(m_albumsManager, SIGNAL(cardAdded(int,QString)),
            this, SLOT(onCardAdded(int,QString)));
}

void AlbumCardsModel::setAlbumsManager(AlbumsManager *albumsManager)
{
    this->m_albumsManager = albumsManager;
}

void AlbumCardsModel::setCardsManager(CardsManager *cardsManager)
{
    this->m_cardsManager = cardsManager;
    this->AbstractCardModel::setCardsManager(m_cardsManager);
}

void AlbumCardsModel::showAlbum(const int albumId)
{
    beginResetModel();
    m_album = m_albumsManager->getAlbum(albumId);
    endResetModel();
}

int AlbumCardsModel::rowCount(const QModelIndex &) const
{
    return this->m_album.getCardMIDs().count();
}
Card AlbumCardsModel::cardForIndex(const QModelIndex &index) const
{
    return this->m_cardsManager->card(m_album.getCardMIDs().at(index.row()));
}

void AlbumCardsModel::onAlbumAdded(const int albumId)
{
    if (albumId != m_album.getId()) return;
    beginResetModel();
    m_album = m_albumsManager->getAlbum(albumId);
    endResetModel();
}


void AlbumCardsModel::onCardAdded(const int albumId, const QString cMID)
{
    if (albumId != m_album.getId()) return;

    const Album updatedAlbum = m_albumsManager->getAlbum(albumId);
    const int row = updatedAlbum.getCardMIDs().indexOf(cMID);

    beginInsertRows(QModelIndex(), row, row);
    m_album = updatedAlbum;
    endInsertRows();

    emit cardAdded(m_album.getNrOfCards());
}
