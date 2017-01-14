#include "card.h"

// Default Constructor
Card::Card()
{
    this->cardMID = 100;
    this->cardID = "Default cardID";
    this->name = "Default name";
    this->imageURL = "Default imageURL";
    this->subtype = "Default subtype";
    this->supertype = "Default supertype";
    this->number = 0;
    this->artist = "Default artist";
    this->rarity = "Default rarity";
    this->series = "Default series";
    this->set = "Default set";
    this->setCode = "Default setCode";
    this->condition = "Default condition";
    this->status = "Default status";
}

// Overloaded Constructor
Card::Card(const int &cardMID, const QString &cardID, const QString &name, const QString &imageURL, const QString &subtype, const QString &supertype, const int &number, const QString &artist, const QString &rarity, const QString &series, const QString &set, const QString &setCode, const QString &condition, const QString &status)
{
    this->cardMID = cardMID;
    this->cardID = cardID;
    this->name = name;
    this->imageURL = imageURL;
    this->subtype = subtype;
    this->supertype = supertype;
    this->number = number;
    this->artist = artist;
    this->rarity = rarity;
    this->series = series;
    this->set = set;
    this->setCode = setCode;
    this->condition = condition;
    this->status = status;
}


// Copy & Assignment
Card::Card(const Card &other)
{
    this->cardMID = other.cardMID;
    this->cardID = other.cardID;
    this->name = other.name;
    this->imageURL = other.imageURL;
    this->subtype = other.subtype;
    this->supertype = other.supertype;
    this->number = other.number;
    this->artist = other.artist;
    this->rarity = other.rarity;
    this->series = other.series;
    this->set = other.set;
    this->setCode = other.setCode;
    this->condition = other.condition;
    this->status = other.status;
}

Card& Card::operator = (const Card &other)
{
    if (this != &other)
    {
        this->cardMID = other.cardMID;
        this->cardID = other.cardID;
        this->name = other.name;
        this->imageURL = other.imageURL;
        this->subtype = other.subtype;
        this->supertype = other.supertype;
        this->number = other.number;
        this->artist = other.artist;
        this->rarity = other.rarity;
        this->series = other.series;
        this->set = other.set;
        this->setCode = other.setCode;
        this->condition = other.condition;
        this->status = other.status;
    }
    return *this;
}


// GETTERS
int Card::getCardMID() const
{
    return this->cardMID;
}


QString Card::getCardID() const
{
    return this->cardID;
}

QString Card::getName() const
{
    return this->name;
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

QString Card::getSet() const
{
    return this->set;
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

// SETTERS
void Card::setCardMID(const int newCardMID)
{
    this->cardMID = newCardMID;
}

void Card::setCardID(const QString newCardID)
{
    this->cardID = newCardID;
}

void Card::setName(const QString newName)
{
    this->name = newName;
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

void Card::setSet(const QString newSet)
{
    this->set = newSet;
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
