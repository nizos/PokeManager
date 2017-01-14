#include "album.h"

// Constructors & Destructor
Album::Album()
{
    this->albumName = "No name";
    this->albumMID = 0;
    this->cardsManager = nullptr;
}


Album::Album(QString albumName, int albumMID, CardsManager *cardsManager)
{
    this->albumName = albumName;
    this->albumMID = albumMID;
    this->cardsManager = cardsManager;
}

Album::~Album()
{
    this->cardsManager = nullptr;
}

int Album::linearSearch(const int cardMID) const
{
    int pos = -1;
    for (int i = 0; i < this->cardMIDs.count() && pos == -1; i++)
    {

        if (this->cardMIDs.at(i) == QString::number(cardMID))
        {
            pos = i;
        }
    }
    return pos;
}


// Album Setters
void Album::setAlbumMID(const int albumMID)
{
    this->albumMID = albumMID;
}

void Album::setAlbumName(const QString albumName)
{
    this->albumName = albumName;
}

// Album Getters
int Album::getAlbumMID() const
{
    return this->albumMID;
}

QString Album::getAlbumName() const
{
    return this->albumName;
}


// Card Getters
int Album::getNrOfCards() const
{
    return this->cardMIDs.count();
}

QString Album::getCardMID(int pos) const
{
    return this->cardMIDs.at(pos);
}

QStringList Album::getCardMIDs() const
{
    return this->cardMIDs;
}


QString Album::getCardOneURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 1)
    {
        return nrUrl;
    }
    return this->cardsManager->getCard(cardMIDs.at(0)).getImageURL();
}

QString Album::getCardTwoURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 2)
    {
        return nrUrl;
    }
    return this->cardsManager->getCard(cardMIDs.at(1)).getImageURL();
}

QString Album::getCardThreeURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 3)
    {
        return nrUrl;
    }
    return this->cardsManager->getCard(cardMIDs.at(2)).getImageURL();
}

QString Album::getCardFourURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 4)
    {
        return nrUrl;
    }
    return this->cardsManager->getCard(cardMIDs.at(3)).getImageURL();
}

bool Album::getCardOneLoaded() const
{
    if (this->cardMIDs.count() < 1)
    {
        return false;
    }
    return this->cardsManager->getCard(cardMIDs.at(0)).getLoaded();
}

bool Album::getCardTwoLoaded() const
{
    if (this->cardMIDs.count() < 2)
    {
        return false;
    }
    return this->cardsManager->getCard(cardMIDs.at(1)).getLoaded();
}

bool Album::getCardThreeLoaded() const
{
    if (this->cardMIDs.count() < 3)
    {
        return false;
    }
    return this->cardsManager->getCard(cardMIDs.at(2)).getLoaded();
}

bool Album::getCardFourLoaded() const
{
    if (this->cardMIDs.count() < 4)
    {
        return false;
    }
    return this->cardsManager->getCard(cardMIDs.at(3)).getLoaded();
}
// Management
void Album::addCard(const int cardMID)
{
    this->cardMIDs << QString::number(cardMID);
}

void Album::removeCard(const int cardMID)
{
    int pos = this->linearSearch(cardMID);
    if (pos == -1)
    {
        QString exc = "CardMID cMID not found.";
        throw exc;
    }
    this->cardMIDs.removeAt(pos);
}
