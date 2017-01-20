#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include "resourceimageprovider.h"
#include <QNetworkAccessManager>
#include <QHash>
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QSqlQuery>
#include <QSignalMapper>


class ImageHandler : public QObject
{
     Q_OBJECT
public:
    ImageHandler(QObject* parent = 0);
//    QImage requestImage(const QString &imageURL);

//signals:
//    void cardAdded(QString imageURL);
//    void cardUpdated(QString imageURL);
//    void mapped(QString imageURL);

//public slots:
//    void mappedReply(QString imageURL);

//private:
//    QSqlDatabase db;
//    QNetworkAccessManager *m_nam;
//    QSignalMapper m_mapper;
//    QHash<QString, QNetworkReply*> m_replies;
//    ResourceImageProvider* m_imageProvider;
};

#endif // IMAGEHANDLER_H
