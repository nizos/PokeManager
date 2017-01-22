#include "resourceimageprovider.h"

ResourceImageProvider::ResourceImageProvider(QObject *parent)  :QQuickImageProvider(QQuickImageProvider::Image), QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(&m_mapper, SIGNAL(mapped(QString)), this,
    SLOT(mappedReply(QString)));
}

ResourceImageProvider::~ResourceImageProvider()
{
    delete this->manager;
}


//void ResourceImageProvider::setCardsSQLModel(CardsSQLModel* cardsSQLModel)
//{
//    this->cardsSQLModel = cardsSQLModel;
//}

void ResourceImageProvider::setSQLDatabase(QSqlDatabase* db)
{
    this->db = db;
}

QImage ResourceImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    // Check for image in database
    QString addQuote = "'" + id + "'";
    QString qslSelect = "SELECT * FROM CardImages2 WHERE imageURL=:imageURL";
    QSqlQuery findCard;
    findCard.prepare(qslSelect);
    findCard.bindValue(":imageURL",id);
    if(findCard.exec())
    {
        if(findCard.first())
        {
            // Image found in database
            qDebug() << "Image found in db.";
            QByteArray outByteArray = findCard.value(1).toByteArray();
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( outByteArray );
            QImage cardImage;
            cardImage = outPixmap.toImage();
//            cardImage.scaledToHeight(size->height());
//            cardImage.scaledToWidth(size->width());
            return cardImage;
        }
        else
        {
            // Image not found in database
            qDebug() << "Image not found in db.";

            // Request Image from Network
            QUrl url(id);
            QNetworkReply* reply = manager->get(QNetworkRequest(url));
            connect(reply, SIGNAL(finished()), &m_mapper, SLOT(map()));
            m_replies.insert(id, reply);
            m_mapper.setMapping(reply, id);

            // return temporary image place holder
            QPixmap tempPixmap;
            tempPixmap.load(":/gui/GUI/emptyCard.png");
            QImage temp;
            temp = tempPixmap.toImage();
//            temp.scaledToHeight(size->height());
//            temp.scaledToWidth(size->width());
//            emit cardAdded(id);
            return temp;
        }
    }
    else
    {
        // Couldn't perform SQLQuery
        qDebug() << "Error: Couldn't perform SQLQuery.\n" << db->lastError();
        QPixmap tempPixmap;
        tempPixmap.load(":/gui/GUI/emptyCard.png");
        QImage temp;
        temp = tempPixmap.toImage();
//        temp.scaledToHeight(size->height());
//        temp.scaledToWidth(size->width());
//        emit cardAdded(id);
        return temp;
    }
}

//void ResourceImageProvider::addCardImage(QString imageURL, int crdID, int albID)
//{
//    // Request Image from Network
//    QUrl url(imageURL);
//    QNetworkReply* reply = manager->get(QNetworkRequest(url));
//    reply->setProperty("crdID", crdID);
//    reply->setProperty("albID", albID);
//    connect(reply, SIGNAL(finished()), &m_mapper, SLOT(map()));
//    m_replies.insert(imageURL, reply);
//    m_mapper.setMapping(reply, imageURL);

//}

void ResourceImageProvider::mappedReply(QString id)
{
    QNetworkReply *reply = m_replies.take(id);
    const QByteArray data = reply->readAll();




    QImage img;
    if(img.loadFromData(data,"PNG"))
    {
        qDebug() << "Image loaded";
        // Insert image into database
        QString addQuote = "'" + id + "'";
        QString qslUpdate = "UPDATE CardImages2 SET imageData=:imageData WHERE imageURL=:imageURL";
        QSqlQuery updateCard;
        updateCard.prepare(qslUpdate);
        updateCard.bindValue(":imageData",img);
        updateCard.bindValue(":imageURL",id);
        if(updateCard.exec())
        {
//            if(reply->property("crdID").isValid())
//            {
//                qDebug() << "Requested Card Image Added.";
//                emit cardImageAdded(reply->property("albID").toInt(), reply->property("crdID").toInt());
//            }
//            else
//            {
                emit cardUpdated(id);
                qDebug() << "Card Image Added.";
//            }
        }
        else
        {
            qDebug() << "ERROR: Couldn't update imageData for card: " << id;
            qDebug() << db->lastError();
        }
    }
    else
    {
        qDebug() << "ERROR: Couldn't load image: " << id;
    }
    reply->deleteLater();
}



//    // Make Network Request
//    QUrl url(id);
//    QNetworkReply* reply = manager->get(QNetworkRequest(url));

////    // Wait for Response
//    QEventLoop eventLoop;
//    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
//    eventLoop.exec();

//    // Error!!
//    if (reply->error() != QNetworkReply::NoError)
//    {
//        return QImage();
//    }

//    // Return Image
//    QImage image = QImage::fromData(reply->readAll());
//    size->setWidth(image.width());
//    size->setHeight(image.height());
//    return image;
//}
