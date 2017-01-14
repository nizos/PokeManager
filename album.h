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
    int albumId;
    QString albumName;
    QStringList cardMIDs;

    int linearSearch(const int cMID) const;
    CardsManager *cardsManager;

public:
    // Constructors & Destructor
    Album();
    Album(QString albumName, int albumId, CardsManager *cardsManager);
    ~Album();

    // Album Setters
    void setName(const QString albumName);
    void setId(const int albumId);

    // Album Getters
    int getId() const;
    QString getName() const;

    // Card Getters
    int getNrOfCards() const;
    QString getCardMID(int pos) const;
    QStringList getCardMIDs() const;

    QString getCardOneURL() const;
    QString getCardTwoURL() const;
    QString getCardThreeURL() const;
    QString getCardFourURL() const;

    // Management
    void addCard(const int cMID);
    void removeCard(const int cMID);

};

#endif // ALBUM_H
