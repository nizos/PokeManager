#ifndef RESOURCEIMAGEPROVIDER_H
#define RESOURCEIMAGEPROVIDER_H
#include <QQuickImageProvider>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QObject>
#include <QPixmap>
#include <QImage>


class ResourceImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    ResourceImageProvider(QObject *parent = 0);
    ~ResourceImageProvider();

    QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);

//public slots:
//    void imageFromURL(QImage *image);

//signals:
//    void imageReady(const QString &id);

protected:
    QNetworkAccessManager *manager;
//    QImage *image;
};

#endif // RESOURCEIMAGEPROVIDER_H
