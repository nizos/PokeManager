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
#include <QHash>
#include <QSignalMapper>


class ResourceImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    ResourceImageProvider(QObject *parent = 0);
    ~ResourceImageProvider();

    QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);
//    QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);



protected:
    QNetworkAccessManager *manager;
};

#endif // RESOURCEIMAGEPROVIDER_H
