#include "resourceimageprovider.h"

ResourceImageProvider::ResourceImageProvider(QObject *parent)  :QQuickImageProvider(QQuickImageProvider::Image,QQuickImageProvider::ForceAsynchronousImageLoading)
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
//    QString serverName = "LOCALHOST\\SQLEXPRESS";
//    QString dbName = "pokeManager";
//    this->m_db = QSqlDatabase::addDatabase("QODBC");
//    this->m_db.setConnectOptions();
//    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
//    m_db.setDatabaseName(dsn);
//    if(db->open())
//    {
//        qDebug() << "Connection to database opened.";
        // Check for image in database
        QString addQuote = "'" + id + "'";
        QString qslSelect = "SELECT * FROM CardImages2 WHERE imageURL = " + addQuote;
        qDebug() << qslSelect;
        QSqlQuery findCard;
        if(findCard.exec(qslSelect))
        {
            // Image found in database
            if(findCard.first())
            {
                qDebug() << "Image found in db.";
                QByteArray outByteArray = findCard.value(1).toByteArray();
                QPixmap outPixmap = QPixmap();
                outPixmap.loadFromData( outByteArray );
                QImage cardImage;
                cardImage = outPixmap.toImage();
//                m_db.close();
                return cardImage;
            }
            // Image not found in database
            else
            {
                // Request Image from Network
//                m_db.close();
                qDebug() << "Image not found in db.";
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
                emit cardAdded(id);
                return temp;
            }
        }
        // Couldn't perform SQLQuery
        else
        {

            // Print database error
            qDebug() << "Error: Couldn't perform SQLQuery.\n" << db->lastError();
//            m_db.close();
            // return temporary image place holder
            QPixmap tempPixmap;
            tempPixmap.load(":/gui/GUI/emptyCard.png");
            QImage temp;
            temp = tempPixmap.toImage();
            emit cardAdded(id);
            return temp;
        }
    }
//    else
//    {
//        qDebug() << "ERROR: Couldn't connect to database!\n" << m_db.lastError();
//        // return temporary image place holder
//        QPixmap tempPixmap;
//        tempPixmap.load(":/gui/GUI/emptyCard.png");
//        QImage temp;
//        temp = tempPixmap.toImage();
//        emit cardAdded(id);
//        return temp;
//    }
//}

void ResourceImageProvider::mappedReply(QString id)
{
    QNetworkReply *reply = m_replies.take(id);
    const QByteArray data = reply->readAll();

    QImage img;
    if(img.loadFromData(data,"PNG"))
    {
        qDebug() << "Image loaded";
    }
    else
    {
        qDebug() << "ERROR: Couldn't load image: " << id;;
    }

//    cardsSQLModel->
    emit cardUpdated(id);
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
