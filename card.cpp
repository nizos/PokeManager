#include "card.h"

// Default Constructor
Card::Card()
{
    this->albumMID = -1;
    this->cardMID = 100;
    this->cardID = "Default cardID";
    this->cardName = "Default card name";
    this->imageURL = "qrc:/gui/GUI/emptyCard.png";
    this->subtype = "Default subtype";
    this->supertype = "Default supertype";
    this->number = 0;
    this->artist = "Default artist";
    this->rarity = "Default rarity";
    this->series = "Default series";
    this->setName = "Default setName";
    this->setCode = "Default setCode";
    this->condition = "Default condition";
    this->status = "Default status";
    this->loaded = false;
    this->cardAdded = QDateTime::currentDateTime();
    this->cardEdited = QDateTime::currentDateTime();
}

Card::Card(const int &albumMID, const int &cardMID)
{
    this->albumMID = albumMID;
    this->cardMID = cardMID;
    this->cardID = "Default cardID";
    this->cardName = "Default card name";
    this->imageURL = "qrc:/gui/GUI/emptyCard.png";
    this->subtype = "Default subtype";
    this->supertype = "Default supertype";
    this->number = 0;
    this->artist = "Default artist";
    this->rarity = "Default rarity";
    this->series = "Default series";
    this->setName = "Default setName";
    this->setCode = "Default setCode";
    this->condition = "Default condition";
    this->status = "Default status";
    this->loaded = false;
    this->cardAdded = QDateTime::currentDateTime();
    this->cardEdited = QDateTime::currentDateTime();
}

// Overloaded Constructor
Card::Card(const int &albumMID, const int &cardMID, const QString &cardID, const QString &cardName, const QString &imageURL, const QString &subtype, const QString &supertype, const int &number, const QString &artist, const QString &rarity, const QString &series, const QString &setName, const QString &setCode, const QString &condition, const QString &status, const QDateTime &cardAdded, const QDateTime &cardEdited)
{
    this->albumMID = albumMID;
    this->cardMID = cardMID;
    this->cardID = cardID;
    this->cardName = cardName;
    this->imageURL = imageURL;
    this->subtype = subtype;
    this->supertype = supertype;
    this->number = number;
    this->artist = artist;
    this->rarity = rarity;
    this->series = series;
    this->setName = setName;
    this->setCode = setCode;
    this->condition = condition;
    this->status = status;
    this->loaded = true;
    this->cardAdded = cardAdded;
    this->cardEdited = cardEdited;
}


// Copy & Assignment
Card::Card(const Card &other)
{
    this->albumMID = other.albumMID;
    this->cardMID = other.cardMID;
    this->cardID = other.cardID;
    this->cardName = other.cardName;
    this->imageURL = other.imageURL;
    this->subtype = other.subtype;
    this->supertype = other.supertype;
    this->number = other.number;
    this->artist = other.artist;
    this->rarity = other.rarity;
    this->series = other.series;
    this->setName = other.setName;
    this->setCode = other.setCode;
    this->condition = other.condition;
    this->status = other.status;
    this->loaded = other.loaded;
    this->cardAdded = other.cardAdded;
    this->cardEdited = other.cardEdited;
}

Card& Card::operator = (const Card &other)
{
    if (this != &other)
    {
        this->albumMID = other.albumMID;
        this->cardMID = other.cardMID;
        this->cardID = other.cardID;
        this->cardName = other.cardName;
        this->imageURL = other.imageURL;
        this->subtype = other.subtype;
        this->supertype = other.supertype;
        this->number = other.number;
        this->artist = other.artist;
        this->rarity = other.rarity;
        this->series = other.series;
        this->setName = other.setName;
        this->setCode = other.setCode;
        this->condition = other.condition;
        this->status = other.status;
        this->loaded = other.loaded;
        this->cardAdded = other.cardAdded;
        this->cardEdited = other.cardEdited;
    }
    return *this;
}


// GETTERS
int Card::getAlbumMID() const
{
    return this->albumMID;
}

int Card::getCardMID() const
{
    return this->cardMID;
}


QString Card::getCardID() const
{
    return this->cardID;
}

QString Card::getCardName() const
{
    return this->cardName;
}

QString Card::getImageURL() const
{
    return this->imageURL;
}

QString Card::getSubtype() const
{
    return this->subtype;
}

QString Card::getSupertype() const
{
    return this->supertype;
}

int Card::getNumber() const
{
    return this->number;
}

QString Card::getArtist() const
{
    return this->artist;
}

QString Card::getRarity() const
{
    return this->rarity;
}

QString Card::getSeries() const
{
    return this->series;
}

QString Card::getSetName() const
{
    return this->setName;
}

QString Card::getSetCode() const
{
    return this->setCode;
}

QString Card::getCondition() const
{
    return this->condition;
}

QString Card::getStatus() const
{
    return this->status;
}

bool Card::getLoaded() const
{
    return this->loaded;
}

QDateTime Card::getCardAdded() const
{
    return this->cardAdded;
}

QDateTime Card::getCardEdited() const
{
    return this->cardEdited;
}

// SETTERS
void Card::setAlbumMID(const int albumMID)
{
    this->albumMID = albumMID;
}

void Card::setCardMID(const int newCardMID)
{
    this->cardMID = newCardMID;
}

void Card::setCardID(const QString newCardID)
{
    this->cardID = newCardID;
}

void Card::setCardName(const QString newCardName)
{
    this->cardName = newCardName;
}

void Card::setImageURL(const QString newImageURL)
{
    this->imageURL = newImageURL;
}

void Card::setSubtype(const QString newSubtype)
{
    this->subtype = newSubtype;
}

void Card::setSupertype(const QString newSupertype)
{
    this->supertype = newSupertype;
}

void Card::setNumber(const int newNumber)
{
    this->number = newNumber;
}

void Card::setArtist(const QString newArtist)
{
    this->artist = newArtist;
}

void Card::setRarity(const QString newRarity)
{
    this->rarity = newRarity;
}

void Card::setSeries(const QString newSeries)
{
    this->series = newSeries;
}

void Card::setSetName(const QString newSetName)
{
    this->setName = newSetName;
}

void Card::setSetCode(const QString newSetCode)
{
    this->setCode = newSetCode;
}

void Card::setCondition(const QString newCondition)
{
    this->condition = newCondition;
}

void Card::setStatus(const QString newStatus)
{
    this->status = newStatus;
}

void Card::setLoaded(const bool loaded)
{
    this->loaded = loaded;
}

void Card::setCardEdited()
{
    this->cardEdited  = QDateTime::currentDateTime();
}
