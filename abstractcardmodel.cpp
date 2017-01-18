#include "abstractcardmodel.h"

// Default Constructor
AbstractCardModel::AbstractCardModel(QObject *parent): QAbstractListModel(parent)
{
    m_cardManagerPointer = nullptr;
}

// Default Constructor
AbstractCardModel::AbstractCardModel(CardsManager *cardManagerPointer, QObject *parent): QAbstractListModel(parent)
{
    this->m_cardManagerPointer = cardManagerPointer;
}

void AbstractCardModel::setCardsManager(CardsManager *cardManagerPointer)
{
    this->m_cardManagerPointer = cardManagerPointer;
}



QVariant AbstractCardModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= this->m_cardManagerPointer->getNrOfCards())
        return QVariant();

    const Card &card = cardForIndex(index);
    if (role == AlbumMIDRole)
        return card.getAlbumMID();
    else if (role == CardIDRole)
        return card.getCardID();
    else if (role == CardMIDRole)
        return card.getCardMID();
    else if (role == CardNameRole)
        return card.getCardName();
    else if (role == ImageURLRole)
        return card.getImageURL();
    else if (role == SubtypeRole)
        return card.getSubtype();
    else if (role == SupertypeRole)
        return card.getSupertype();
    else if (role == NumberRole)
        return card.getNumber();
    else if (role == ArtistRole)
        return card.getArtist();
    else if (role == RarityRole)
        return card.getRarity();
    else if (role == SeriesRole)
        return card.getSeries();
    else if (role == SetNameRole)
        return card.getSetName();
    else if (role == SetCodeRole)
        return card.getSetCode();
    else if (role == ConditionRole)
        return card.getCondition();
    else if (role == StatusRole)
        return card.getStatus();
    else if(role == LoadedRole)
        return card.getLoaded();
    return QVariant();
}

// Role names
QHash<int, QByteArray> AbstractCardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[AlbumMIDRole] = "albumMID";
    roles[CardIDRole] = "cardID";
    roles[CardMIDRole] = "cardMID";
    roles[CardNameRole] = "cardName";
    roles[ImageURLRole] = "imageURL";
    roles[SubtypeRole] = "subtype";
    roles[SupertypeRole] = "supertype";
    roles[NumberRole] = "number";
    roles[ArtistRole] = "artist";
    roles[RarityRole] = "rarity";
    roles[SeriesRole] = "series";
    roles[SetNameRole] = "setName";
    roles[SetCodeRole] = "setCode";
    roles[ConditionRole] = "condition";
    roles[StatusRole] = "status";
    roles[LoadedRole] = "loaded";
    return roles;
}
