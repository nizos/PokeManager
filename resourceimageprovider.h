#ifndef RESOURCEIMAGEPROVIDER_H
#define RESOURCEIMAGEPROVIDER_H
#include "cardssqlmodel.h"
#include <QQuickImageProvider>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QSqlQuery>
#include <QSqlError>
#include <QBuffer>
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
//    void setCardsSqlModel(CardsSQLModel* cardsSQLModel);
    void setSQLDatabase(QSqlDatabase* db);

signals:
    void cardAdded(QString imageURL);
    void cardUpdated(QString imageURL);
    void mapped(QString imageURL);

public slots:
    void mappedReply(QString);

protected:
    QSqlDatabase* db;
    QSignalMapper m_mapper;
    QHash<QString, QNetworkReply*> m_replies;
    CardsSQLModel* cardsSQLModel;
    QNetworkAccessManager *manager;
};

#endif // RESOURCEIMAGEPROVIDER_H
