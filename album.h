#ifndef ALBUM_H
#define ALBUM_H
#include <QDebug>
#include <QString>
#include <QList>
#include "cardsmanager.h"
#include "card.h"

class Album
{
private:
    // Private variables
    int albumMID;
    QString albumName;
    QStringList cardMIDs;

    int linearSearch(const int cardMID) const;
    CardsManager *cardsManager;

public:
    // Constructors & Destructor
    Album();
    Album(QString albumName, int albumMID, CardsManager *cardsManager);
    ~Album();

    // Album Setters
    void setAlbumName(const QString albumName);
    void setAlbumMID(const int albumMID);

    // Album Getters
    int getAlbumMID() const;
    QString getAlbumName() const;

    // Card Getters
    int getNrOfCards() const;
    QString getCardMID(int pos) const;
    QStringList getCardMIDs() const;

    QString getCardOneURL() const;
    QString getCardTwoURL() const;
    QString getCardThreeURL() const;
    QString getCardFourURL() const;

    // Management
    void addCard(const int cardMID);
    void removeCard(const int cardMID);

};

#endif // ALBUM_H
