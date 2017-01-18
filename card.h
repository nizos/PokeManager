#ifndef CARD_H
#define CARD_H
#include <QDebug>
#include <QDateTime>
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
    int albumMID;
    QString cardID;
    QString cardName;
    QString imageURL;
    QString subtype;
    QString supertype;
    QString nrString;
    int number;
    QString artist;
    QString rarity;
    QString series;
    QString setName;
    QString setCode;
    QString condition;
    QString status;
    bool loaded;
    QDateTime cardAdded;
    QDateTime cardEdited;

public:
    // Constructors & Destructor
    Card();
    Card(const int &albumMID, const int &cardMID);
    Card(const int &albumMID, const int &cardMID, const QString &cardID, const QString &cardName, const QString &imageURL, const QString &subtype, const QString &supertype, const int &number, const QString &artist, const QString &rarity, const QString &series, const QString &setName, const QString &setCode, const QString &condition, const QString &status, const QDateTime &cardAdded, const QDateTime &cardEdited);

    // Copy & Assignment
    Card(const Card &other);
    Card& operator = (const Card &other);

    // GETTERS
    int getAlbumMID() const;
    int getCardMID() const;
    QString getCardID() const;
    QString getCardName() const;
    QString getImageURL() const;
    QString getSubtype() const;
    QString getSupertype() const;
    int getNumber() const;
    QString getArtist() const;
    QString getRarity() const;
    QString getSeries() const;
    QString getSetName() const;
    QString getSetCode() const;
    QString getCondition() const;
    QString getStatus() const;
    bool getLoaded() const;
    QDateTime getCardAdded() const;
    QDateTime getCardEdited() const;

    // SETTERS
    void setAlbumMID(const int albumMID);
    void setCardMID(const int cardMID);
    void setCardID(const QString cardID);
    void setCardName(const QString newCardName);
    void setImageURL(const QString newImageURL);
    void setSubtype(const QString newSubtype);
    void setSupertype(const QString newSupertype);
    void setNumber(const int newNumber);
    void setArtist(const QString newArtist);
    void setRarity(const QString newRarity);
    void setSeries(const QString newSeries);
    void setSetName(const QString newSetName);
    void setSetCode(const QString newSetCode);
    void setCondition(const QString newCondition);
    void setStatus(const QString newStatus);
    void setLoaded(const bool loaded);
    void setCardEdited();
};

#endif // CARD_H
