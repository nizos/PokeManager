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
    if(id == ":/gui/GUI/emptyCard.png")
    {
        // return temporary image place holder
        QPixmap tempPixmap;
        tempPixmap.load(":/gui/GUI/emptyCard.png");
        QImage temp;
        temp = tempPixmap.toImage();
        return temp;
    }
    // Check for image in database
    QString qslSelect = "SELECT * FROM CardImages3 WHERE imageURL=:imageURL";
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
        QString insertImage = "INSERT INTO CardImages3 ([imageURL],[imageData]) VALUES(:imageURL,:imageData)";
        QSqlQuery updateCard;
        updateCard.prepare(insertImage);
        updateCard.bindValue(":imageURL",id);
        updateCard.bindValue(":imageData",data);
        if(updateCard.exec())
        {
            emit cardUpdated(id);
            qDebug() << "Card Image Added.";

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
