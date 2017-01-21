#include "cardssqlmanager.h"

CardsSQLManager::CardsSQLManager()
{
    this->cardMIDs = 1000;
}


void CardsSQLManager::addCard(QString cardReqId)
{
//    QString insertCardCommand = "INSERT INTO [dbo].[Cards]([cardMID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited]) VALUES(:cardMID,:albumMID,:cardID,:name,:imageURL,:subtype,:supertype,:number,:artist,:rarity,:series,:setName,:setCode,:condition,:status,:loaded,:cardAdded,:cardEdited)";

//    QSqlQuery qryCard;
//    qryCard.prepare(insertCardCommand);
//    qryCard.bindValue(":cardMID",cardMIDs);
//    qryCard.bindValue(":albumMID",1001);
//    qryCard.bindValue(":cardID",cardReqId);
//    qryCard.bindValue(":loaded",false);
//    qryCard.bindValue(":cardAdded",QDateTime::currentDateTime());
//    qryCard.bindValue(":cardEdited",QDateTime::currentDateTime());
//    if(qryCard.exec())
//    {
//        this->cardMIDs++;
//        emit cardAdded(cardReqId);
//        qDebug() << "Card 1 Inserted into Cards!";
//    }
//    else
//    {
//        qDebug() << "ERROR: Could not add Card: " << cardMIDs << db->lastError();
//    }

//    // Make Network Request
//    QString requestURL = "https://api.pokemontcg.io/v1/cards/";
//    requestURL.append(cardReqId);
//    QUrl url(requestURL);
//    QNetworkReply* reply = manager->get(QNetworkRequest(url));

//    connect(reply, SIGNAL(finished()), &m_mapper, SLOT(map()));
//    m_replies.insert(cardReqId, reply);
//    m_mapper.setMapping(reply, cardReqId);
}


void CardsSQLManager::removeCard()
{

}


void CardsSQLManager::mappedReply(QString cardReqId)
{
//    QNetworkReply *reply = m_replies.take(cardReqId);
//    const QByteArray data = reply->readAll();

//    // Open JSON document
//    QString val = data;
//    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8());
//    QJsonObject rootObject = jsonDocument.object();
//    QJsonValue value = rootObject.value(QString("card"));
//    QJsonObject cardRootValues = value.toObject();

//    QString insertCardCommand = "INSERT INTO [dbo].[Cards]([name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[cardEdited]) VALUES(:name,:imageURL,:subtype,:supertype,:number,:artist,:rarity,:series,:setName,:setCode,:condition,:status,:cardEdited)";
//    QSqlQuery qryCard;
//    qryCard.prepare(insertCardCommand);
//    qryCard.bindValue(":name",cardRootValues.value("name").toString());
//    qryCard.bindValue(":imageURL",cardRootValues.value("imageUrl").toString());
//    qryCard.bindValue(":subtype",cardRootValues.value("subtype").toString());
//    qryCard.bindValue(":supertype",cardRootValues.value("supertype").toString());
//    qryCard.bindValue(":number",cardRootValues.value("number").toInt());
//    qryCard.bindValue(":artist",cardRootValues.value("artist").toString());
//    qryCard.bindValue(":rarity",cardRootValues.value("rarity").toString());
//    qryCard.bindValue(":series",cardRootValues.value("series").toString());
//    qryCard.bindValue(":setName",cardRootValues.value("set").toString());
//    qryCard.bindValue(":setCode",cardRootValues.value("setCode").toString());
//    qryCard.bindValue(":condition","Not specified");
//    qryCard.bindValue(":status","Not specified");
//    qryCard.bindValue(":cardEdited",QDateTime::currentDateTime());
//    if(qryCard.exec())
//    {
//        qDebug() << "Card 1 Inserted into Cards!";
//        emit cardUpdated(cardReqId);
//    }
//    reply->deleteLater();
}
