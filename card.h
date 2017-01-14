#ifndef CARD_H
#define CARD_H
#include <QDebug>
#include <QObject>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>
#include "mainnetworkmanager.h"

class Card
{
private:
    int cardMID;
    int inAlbumMID;
    QString cardID;
    QString name;
    QString imageURL;
    QString subtype;
    QString supertype;
    QString nrString;
    int number;
    QString artist;
    QString rarity;
    QString series;
    QString set;
    QString setCode;
    QString condition;
    QString status;
    bool loaded;

public:
    // Constructors & Destructor
    Card();
    Card(const int &inAlbumMID, const int &cardMID);
    Card(const int &inAlbumMID, const int &cardMID, const QString &cardID, const QString &name, const QString &imageURL, const QString &subtype, const QString &supertype, const int &number, const QString &artist, const QString &rarity, const QString &series, const QString &set, const QString &setCode, const QString &condition, const QString &status);

    // Copy & Assignment
    Card(const Card &other);
    Card& operator = (const Card &other);

    // GETTERS
    int getInAlbumMID() const;
    int getCardMID() const;
    QString getCardID() const;
    QString getName() const;
    QString getImageURL() const;
    QString getSubtype() const;
    QString getSupertype() const;
    int getNumber() const;
    QString getArtist() const;
    QString getRarity() const;
    QString getSeries() const;
    QString getSet() const;
    QString getSetCode() const;
    QString getCondition() const;
    QString getStatus() const;
    bool getLoaded() const;

    // SETTERS
    void setInAlbumMID(const int inAlbumMID);
    void setCardMID(const int newCardMID);
    void setCardID(const QString newCardID);
    void setName(const QString newName);
    void setImageURL(const QString newImageURL);
    void setSubtype(const QString newSubtype);
    void setSupertype(const QString newSupertype);
    void setNumber(const int newNumber);
    void setArtist(const QString newArtist);
    void setRarity(const QString newRarity);
    void setSeries(const QString newSeries);
    void setSet(const QString newSet);
    void setSetCode(const QString newSetCode);
    void setCondition(const QString newCondition);
    void setStatus(const QString newStatus);
    void setLoaded(const bool loaded);
};

#endif // CARD_H
