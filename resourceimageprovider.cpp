#include "resourceimageprovider.h"

ResourceImageProvider::ResourceImageProvider(QObject *parent) :QQuickImageProvider(QQuickImageProvider::Image,QQmlImageProviderBase::ForceAsynchronousImageLoading)
{
    this->manager = new QNetworkAccessManager();
}

ResourceImageProvider::~ResourceImageProvider()
{
    delete this->manager;
}

QImage ResourceImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    // Make Network Request
    QUrl url(id);
    QNetworkReply* reply = manager->get(QNetworkRequest(url));

    // Wait for Response
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    // Error!!
    if (reply->error() != QNetworkReply::NoError)
    {
        return QImage();
    }

    // Return Image
    QImage image = QImage::fromData(reply->readAll());
    size->setWidth(image.width());
    size->setHeight(image.height());
    return image;
}
