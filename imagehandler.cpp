#include "imagehandler.h"

//ImageHandler::ImageHandler(QObject* parent): QObject(parent)
//{
//    QString serverName = "LOCALHOST\\SQLEXPRESS";
//    QString dbName = "pokeManager";
//    this->db = QSqlDatabase::addDatabase("QODBC");

//    db.setConnectOptions();
//    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
//    db.setDatabaseName(dsn);


//    this->m_nam = new QNetworkAccessManager();

//    connect(&m_mapper, SIGNAL(mapped(QString)), this,
//    SLOT(mappedReply(QString)));
//}

//QImage ImageHandler::requestImage(const QString &imageURL)
//{
//    QString qslSelect = "SELECT TOP 1 [imageData] FROM [dbo].[CardImages] WHERE imageURL = " + imageURL;
//    QSqlQuery findCard;
//    if(db.open())
//    {
//        if(findCard.exec(qslSelect))
//        {
//            if(findCard.first()!= NULL)
//            {
//                QByteArray outByteArray = findCard.value( 0 ).toByteArray();
//                QImage outImage;
//                QBuffer buffer(&outByteArray);
//                buffer.open(QIODevice::WriteOnly);
//                outImage.save(&buffer, ".PNG");
//                db.close();

//                QString image("data:image/png;base64,");
//                image.append(QString::fromLatin1(outByteArray.toBase64().data()));
//                return outImage;
//            }
//            else
//            {
//                db.close();
//                qDebug() << "Image not found.";
//                QSize size;
//                size.setHeight(342);
//                size.setWidth(245);
//                QImage reply = m_imageProvider->requestImage(imageURL,&size,size);
//                connect(reply, SIGNAL(finished()), &m_mapper, SLOT(map()));
//                m_replies.insert(imageURL, reply);
//                m_mapper.setMapping(reply, imageURL);

//                QImage temp = m_imageProvider->requestTempImage();
//                return temp;
//            }
//        }
//        else
//        {
//            qDebug() << "Error: " << db.lastError();
//            QImage temp = m_imageProvider->requestTempImage();
//            return temp;
//        }
//        db.close();
//    }
//    else
//    {
//        qDebug() << "Error: " << db.lastError();
//    }
//}

//void ImageHandler::mappedReply(QString imageURL)
//{
//    QImage *reply = m_replies.take(imageURL);
//    QByteArray inByteArray;
//    QBuffer inBuffer( &inByteArray );
//    inBuffer.open( QIODevice::WriteOnly );
//    reply->save( &inBuffer, "PNG" ); // write inPixmap into inByteArray in PNG format

//    QString qslInsert = "INSERT INTO [dbo].[CardImages] (imageURL, imageData) VALUES (:imageURL,:imageData)";
//    QSqlQuery qryCard;
//    if(db.open())
//    {
//        qryCard.prepare(qslInsert);
//        qryCard.bindValue(":imageURL",imageURL);
//        qryCard.bindValue(":imageData",inByteArray);
//        if(!query.exec())
//        {
//            qDebug() << "Error inserting image into table:\n" << query.lastError();
//        }
//        else
//        {
//            qDebug() << "Card data added to CardImages.";
//        }
//    }
//    else
//    {
//        qDebug() << "Error: " << db.lastError();
//    }
//    reply->deleteLater();
//}
