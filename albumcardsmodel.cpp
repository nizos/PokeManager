#include "albumcardsmodel.h"
AlbumCardsModel::AlbumCardsModel(QObject *parent)
    : AbstractCardModel(parent)
{
    albumsManager = nullptr;
    cardsManager = nullptr;
}

AlbumCardsModel::AlbumCardsModel(AlbumsManager *albumsManager, CardsManager *cardsManager, QObject *parent)
    : AbstractCardModel(cardsManager, parent)
{
    this->albumsManager = albumsManager;
    this->cardsManager = cardsManager;

    connect(albumsManager, SIGNAL(albumAdded(int)),
            this, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),
            this, SLOT(onCardAdded(int,QString)));
}

void AlbumCardsModel::setAlbumsManager(AlbumsManager *albumsManager)
{
    this->albumsManager = albumsManager;
}

void AlbumCardsModel::setCardsManager(CardsManager *cardsManager)
{
    this->cardsManager = cardsManager;
    this->AbstractCardModel::setCardsManager(cardsManager);
}

void AlbumCardsModel::showAlbum(const int albumMID)
{
    beginResetModel();
    album = albumsManager->getAlbum(albumMID);
    endResetModel();
}

int AlbumCardsModel::rowCount(const QModelIndex &) const
{
    return this->album.getCardMIDs().count();
}
Card AlbumCardsModel::cardForIndex(const QModelIndex &index) const
{
    return this->cardsManager->getCard(album.getCardMIDs().at(index.row()));
}

void AlbumCardsModel::onAlbumAdded(const int albumMID)
{
    if (albumMID != album.getAlbumMID()) return;
    beginResetModel();
    album = albumsManager->getAlbum(albumMID);
    endResetModel();
}


void AlbumCardsModel::onCardAdded(const int albumMID, const QString cardMID)
{
    if (albumMID != album.getAlbumMID()) return;

    const Album updatedAlbum = albumsManager->getAlbum(albumMID);
    const int row = updatedAlbum.getCardMIDs().indexOf(cardMID);

    beginInsertRows(QModelIndex(), row, row);
    album = updatedAlbum;
    endInsertRows();

    emit cardAdded(album.getNrOfCards());
}

void AlbumCardsModel::onCardUpdated(const int albumMID, const QString cardMID)
{
    if (albumMID != album.getAlbumMID()) return;

    const Album updatedAlbum = albumsManager->getAlbum(albumMID);
    const int row = updatedAlbum.getCardMIDs().indexOf(cardMID);

    layoutAboutToBeChanged();
    album = updatedAlbum;
    layoutChanged();

    emit cardAdded(album.getNrOfCards());
}
