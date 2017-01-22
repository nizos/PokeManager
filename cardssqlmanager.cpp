#include "cardssqlmanager.h"

CardsSQLManager::CardsSQLManager(QObject* parent): QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(&m_mapper, SIGNAL(mapped(int)), this,
    SLOT(mappedReply(int)));
}

void CardsSQLManager::setDB(QSqlDatabase* db)
{
    this->db = db;
}

void CardsSQLManager::setResourceImageProvider(ResourceImageProvider* resourceImageProvider)
{
    this->resourceImageProvider = resourceImageProvider;
}

void CardsSQLManager::addCard(int albID, QString crdReq)
{
    int crdID;
    QString insertCardCommand = "INSERT INTO [dbo].[Cards3]([albumMID],[loaded],[cardAdded],[cardEdited]) VALUES(:albumMID,:loaded,:cardAdded,:cardEdited)";

    QSqlQuery qryCard;
    qryCard.prepare(insertCardCommand);
    qryCard.bindValue(":albumMID",albID);
//    qryCard.bindValue(":imageURL", ":/gui/GUI/emptyCard.png");
    qryCard.bindValue(":loaded",false);
    qryCard.bindValue(":cardAdded",QDateTime::currentDateTime());
    qryCard.bindValue(":cardEdited",QDateTime::currentDateTime());
    if(qryCard.exec())
    {
        crdID = qryCard.lastInsertId().toInt();
        qDebug() << "Card: " << crdID << " added to Album: " << albID << ".";
        emit cardAdded(albID,crdID);
    }
    else
    {
        qDebug() << "ERROR: Could not add Card: " << crdReq << " to Album: " << albID;
        qDebug() << db->lastError();
    }

    // Make Network Request
    QString requestURL = "https://api.pokemontcg.io/v1/cards/";
    requestURL.append(crdReq);
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(requestURL)));
    connect(reply, SIGNAL(finished()), &m_mapper, SLOT(map()));
    m_replies.insert(crdID, reply);
    m_mapper.setMapping(reply, crdID);
}


void CardsSQLManager::removeCard(int albID, int crdID)
{

    QString removeCardCommand = "DELETE FROM Cards3 WHERE ID =:crdID";
    QSqlQuery qryCard;
    qryCard.prepare(removeCardCommand);
    qryCard.bindValue(":crdID", crdID);
    if(qryCard.exec())
    {
        // Update  Album last edited
        qDebug() << "Card " << crdID << " deleted.";
        emit cardRemoved(albID,crdID);

        QString updateAlbum = "UPDATE Albums2 SET albumEdited=:albumEdited WHERE ID=:albID";
        QSqlQuery qryAlbum;
        qryAlbum.prepare(updateAlbum);
        qryAlbum.bindValue(":albID", albID);
        qryAlbum.bindValue(":albumEdited", QDateTime::currentDateTime());
        if(qryAlbum.exec())
        {
            qDebug() << "Album " << albID << ": lastEdited updated.";
            emit albumUpdated(albID);
        }
        else
        {
            qDebug() << "Couldn't update Album " << albID << ": lastEdited.";
            qDebug() << db->lastError();
        }

    }
    else
    {
        qDebug() << "Couldn't remove Card " << crdID << ".";
        qDebug() << db->lastError();
    }
}


void CardsSQLManager::mappedReply(int crdID)
{
    int albID;
    qDebug() << "Mapped response for card " << crdID << " received.";
    QNetworkReply *reply = m_replies.take(crdID);
    const QByteArray data = reply->readAll();

    // Open JSON document
    QString val = data;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject rootObject = jsonDocument.object();
    QJsonValue value = rootObject.value(QString("card"));
    QJsonObject cardRootValues = value.toObject();

    // Get Album ID
    QString selectAlbumCardsCommand = "SELECT * FROM Cards3 WHERE ID =:crdID";
    QSqlQuery qrySelectCards;
    qrySelectCards.prepare(selectAlbumCardsCommand);
    qrySelectCards.bindValue(":crdID",crdID);
    if(qrySelectCards.exec())
    {
        if(qrySelectCards.first())
        {
            // Retreived Album ID
            albID = qrySelectCards.value(1).toInt();
            qDebug() << "Album ID:" << albID << " retreived for Card " << crdID << " in mappedReply.";
        }
        else
        {
            qDebug() << "Album ID:coudln't be found by mappedReply for Card: " << crdID;
        }

    }
    else
    {
        // Failed to retreive Album ID
        qDebug() << "Album ID coudln't be retreived for Card " << crdID << " in mappedReply.";
        qDebug() << db->lastError();
    }

    QString insertCardCommand = "UPDATE Cards3 SET cardID=:cardID, name=:name, imageURL=:imageURL, subtype=:subtype, supertype=:supertype, number=:number, artist=:artist, rarity=:rarity, series=:series, setName=:setName, setCode=:setCode, condition=:condition, status=:status, loaded=:loaded, cardEdited=:cardEdited WHERE ID=:crdID";
    QSqlQuery qryCard;
    qryCard.prepare(insertCardCommand);
    qryCard.bindValue(":cardID",cardRootValues.value("id").toString());
    qryCard.bindValue(":name",cardRootValues.value("name").toString());
    qryCard.bindValue(":imageURL",cardRootValues.value("imageUrl").toString());
    qryCard.bindValue(":subtype",cardRootValues.value("subtype").toString());
    qryCard.bindValue(":supertype",cardRootValues.value("supertype").toString());
    qryCard.bindValue(":number",cardRootValues.value("number").toInt());
    qryCard.bindValue(":artist",cardRootValues.value("artist").toString());
    qryCard.bindValue(":rarity",cardRootValues.value("rarity").toString());
    qryCard.bindValue(":series",cardRootValues.value("series").toString());
    qryCard.bindValue(":setName",cardRootValues.value("set").toString());
    qryCard.bindValue(":setCode",cardRootValues.value("setCode").toString());
    qryCard.bindValue(":condition","Not specified");
    qryCard.bindValue(":status","Not specified");
    qryCard.bindValue(":loaded",true);
    qryCard.bindValue(":cardEdited",QDateTime::currentDateTime());
    qryCard.bindValue(":crdID", crdID);
    if(qryCard.exec())
    {
        // Update  Album last edited
        qDebug() << "Card 1 Inserted into Cards!";
//        this->resourceImageProvider->addCardImage(cardRootValues.value("imageUrl").toString(), crdID,albID);
        emit cardUpdated(albID,crdID);

        QString updateAlbum = "UPDATE Albums2 SET albumEdited=:albumEdited WHERE ID=:albID";
        QSqlQuery qryAlbum;
        qryAlbum.prepare(updateAlbum);
        qryAlbum.bindValue(":albID", albID);
        qryAlbum.bindValue(":albumEdited", QDateTime::currentDateTime());
        if(qryAlbum.exec())
        {
            qDebug() << "Album " << albID << ": lastEdited updated.";
            emit albumUpdated(albID);
        }
        else
        {
            qDebug() << "Couldn't update Album " << albID << ": lastEdited.";
            qDebug() << db->lastError();
        }

    }
    else
    {
        qDebug() << "Couldn't update Card " << crdID << ".";
        qDebug() << db->lastError();
    }
    reply->deleteLater();
}

//void CardsSQLManager::cardImageAdded(int albID, int crdID)
//{
//    QString updateCardCommand = "UPDATE Cards3 SET loaded=:loaded WHERE ID=:crdID";
//    QSqlQuery qryCard;
//    qryCard.prepare(updateCardCommand);
//    qryCard.bindValue(":loaded",true);
//    qryCard.bindValue(":crdID", crdID);
//    if(qryCard.exec())
//    {
//        // Update  Album last edited
//        qDebug() << "Card " << crdID << " in Album " << albID << " is now loaded.";

//        emit cardUpdated(albID,crdID);
//    }
//    else
//    {
//        qDebug() << "Couldn't set Card " << crdID << " in Album " << albID << " to loaded.";
//        qDebug() << db->lastError();
//    }
//}
