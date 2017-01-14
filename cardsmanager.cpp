#include "cardsmanager.h"

CardsManager::CardsManager(QObject* parent): QObject(parent)
{
    this->cardMIDs = 1000;
    connect(&networkManager,SIGNAL(readyData(QByteArray)),
            this,SLOT(dataFromNetwork(QByteArray)));
}

int CardsManager::linearSearch(const int cardMID) const
{
    int pos = -1;
    for (int i = 0; i < this->cards.count() && pos == -1; i++)
    {
        if (QString::number(this->cards[i].getCardMID()) == QString::number(cardMID))
        {
            pos = i;
        }
    }
    return pos;
}

void CardsManager::dataFromNetwork(QByteArray data)
{
    // Open JSON document
    QString val = data;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject rootObject = jsonDocument.object();
    QJsonValue value = rootObject.value(QString("card"));
    QJsonObject cardRootValues = value.toObject();

    int pos = linearSearch(cardMIDs);
    if (pos == -1)
    {
        QString exc = "cardMID Id not found.";
        throw exc;
    }
    cards[pos].setName(cardRootValues.value("name").toString());
    cards[pos].setCardID(cardRootValues.value("id").toString());
    cards[pos].setSubtype(cardRootValues.value("subtype").toString());
    cards[pos].setSupertype(cardRootValues.value("supertype").toString());
    cards[pos].setNumber(cardRootValues.value("number").toInt());
    cards[pos].setArtist(cardRootValues.value("artist").toString());
    cards[pos].setRarity(cardRootValues.value("rarity").toString());
    cards[pos].setSeries(cardRootValues.value("series").toString());
    cards[pos].setSet(cardRootValues.value("set").toString());
    cards[pos].setSetCode(cardRootValues.value("setCode").toString());
    cards[pos].setImageURL(cardRootValues.value("imageUrl").toString());
    cards[pos].setStatus("Not specified");
    cards[pos].setCondition("Not specified");
    cards[pos].setLoaded(true);
    int albumMID = cards[pos].getInAlbumMID();
    QString cardMIDString = QString::number(cardMIDs);
    emit cardUpdated(albumMID,cardMIDString);
}

int CardsManager::addCard(const int &albumMID, const QString &cardReq)
{
    cardMIDs++;
    int cardMID = cardMIDs;
    Card newCard(albumMID,cardMID);
    this->cards << newCard;
    emit cardAdded(albumMID,QString::number(cardMID));

    QString requestURL = "https://api.pokemontcg.io/v1/cards/";
    requestURL.append(cardReq);
    networkManager.makeRequest(requestURL);
    return cardMID;
}

int CardsManager::getNrOfCards() const
{
    return this->cards.count();
}

Card CardsManager::getCard(const QString cardMID) const
{
    int pos = this->linearSearch(cardMID.toInt());
    if (pos == -1)
    {
        QString exc = "cardMID Id not found.";
        throw exc;
    }
    return this->cards[pos];
}

QList<Card> CardsManager::getCards() const
{
    return this->cards;
}
