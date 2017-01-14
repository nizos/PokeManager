#include "album.h"

// Constructors & Destructor
Album::Album()
{
    this->albumName = "No name";
    this->albumId = 0;
    this->cardsManager = nullptr;
}


Album::Album(QString albumName, int albumId, CardsManager *cardsManager)
{
    this->albumName = albumName;
    this->albumId = albumId;
    this->cardsManager = cardsManager;
}

Album::~Album()
{
    this->cardsManager = nullptr;
}

int Album::linearSearch(const int cMID) const
{
    int pos = -1;
    for (int i = 0; i < this->cardMIDs.count() && pos == -1; i++)
    {

        if (this->cardMIDs.at(i) == QString::number(cMID))
        {
            pos = i;
        }
    }
    return pos;
}


// Album Setters
void Album::setName(const QString albumName)
{
    this->albumName = albumName;
}

void Album::setId(const int albumId)
{
    this->albumId = albumId;
}


// Album Getters
int Album::getId() const
{
    return this->albumId;
}

QString Album::getName() const
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
    return this->cardsManager->card(cardMIDs.at(0)).getImageURL();
}

QString Album::getCardTwoURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 2)
    {
        return nrUrl;
    }
    return this->cardsManager->card(cardMIDs.at(1)).getImageURL();
}

QString Album::getCardThreeURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 3)
    {
        return nrUrl;
    }
    return this->cardsManager->card(cardMIDs.at(2)).getImageURL();
}

QString Album::getCardFourURL() const
{
    QString nrUrl = "NoURL";
    if (this->cardMIDs.count() < 4)
    {
        return nrUrl;
    }
    return this->cardsManager->card(cardMIDs.at(3)).getImageURL();
}


// Management
void Album::addCard(const int cMID)
{
    this->cardMIDs << QString::number(cMID);
}

void Album::removeCard(const int cMID)
{
    int pos = this->linearSearch(cMID);
    if (pos == -1)
    {
        QString exc = "Card cMID not found.";
        throw exc;
    }
    this->cardMIDs.removeAt(pos);
}
