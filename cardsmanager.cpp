#include "cardsmanager.h"

CardsManager::CardsManager(QObject* parent): QObject(parent)
{
    this->m_cardMID = 1000;
    connect(&m_networkManager,SIGNAL(readyData(QByteArray)),
            this,SLOT(dataFromNetwork(QByteArray)));
}

int CardsManager::linearSearch(const QString cMID) const
{
    int pos = -1;
    for (int i = 0; i < this->m_cards.count() && pos == -1; i++)
    {
        if (QString::number(this->m_cards[i].getCardMID()) == cMID)
        {
            pos = i;
        }
    }
    return pos;
}

void CardsManager::dataFromNetwork(QByteArray data)
{
    this->m_data = data;
}

int CardsManager::addCard(const QString id)
{
    // Request JSON for Card
    QString requestURL = "https://api.pokemontcg.io/v1/cards/";
    requestURL.append(id);
    m_networkManager.makeRequest(requestURL);

    // Wait for response
    QEventLoop loop;
    connect(&m_networkManager, SIGNAL(qnamFinished()),&loop, SLOT(quit()));
    loop.exec();

    // Open JSON document
    QString val = m_data;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject rootObject = jsonDocument.object();
    QJsonValue value = rootObject.value(QString("card"));
    QJsonObject cardRootValues = value.toObject();

    // Set values for card variables
    m_cardMID++;
    int cardMID = m_cardMID;
    QString name = cardRootValues.value("name").toString();
    QString cardId = cardRootValues.value("id").toString();
    QString subtype = cardRootValues.value("subtype").toString();
    QString supertype = cardRootValues.value("supertype").toString();
    QString nrString = cardRootValues.value("number").toString();
    int number = nrString.toInt();
    QString artist = cardRootValues.value("artist").toString();
    QString rarity = cardRootValues.value("rarity").toString();
    QString series = cardRootValues.value("series").toString();
    QString set = cardRootValues.value("set").toString();
    QString setCode = cardRootValues.value("setCode").toString();
    QString imageUrl = cardRootValues.value("imageUrl").toString();
    QString status = "Not specified";
    QString condition = "Not specified";

    Card newCard(cardMID, cardId, name, imageUrl, subtype, supertype, number, artist, rarity, series, set, setCode, condition, status);
    this->m_cards << newCard;

    // For debugging purposes
    qDebug() << "[CardsManager] Card: " << cardMID << cardId << name << imageUrl << subtype << supertype << number << artist << rarity << series << set << setCode << condition << status;

    cardAdded(QString::number(cardMID));
    return cardMID;
}

int CardsManager::getNrOfCards() const
{
    return this->m_cards.count();
}

Card CardsManager::card(const QString cMID) const
{
    int pos = this->linearSearch(cMID);
    if (pos == -1)
    {
        QString exc = "Card Id not found.";
        throw exc;
    }
    return this->m_cards[pos];
}

QList<Card> CardsManager::cards() const
{
    return this->m_cards;
}
