#ifndef ALBUMSMODEL_H
#define ALBUMSMODEL_H
#include <QObject>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QVector>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QModelIndex>
#include "abstractAlbummodel.h"
#include "albumsmanager.h"
#include "albums.h"


class AlbumsModel : public AbstractAlbumModel
{
    Q_OBJECT
public:
    enum AlbumRoles { AlbumNameRole = Qt::UserRole + 1};

    AlbumsModel(QObject *parent = 0);
    AlbumsModel(AlbumsManager *albumsManager, QObject *parent = 0);

    void setAlbumsManager(AlbumsManager *albumsManager);
    void setCardsManager(CardsManager *cardsManager);
    void showAlbums();
    int rowCount(const QModelIndex &parent) const;

protected:
    Album albumForIndex(const QModelIndex &index) const;

signals:
    void albumAdded(const int nrOfAlbums);
    void cardUpdated();

private slots:
    void onAlbumAdded(const int &albumId);
    void onCardAdded(const int &albumId, const QString &cMID);
    void onCardUpdated(const int albumMID, const QString cardMID);

private:
    AlbumsManager *m_albumsManager;
    CardsManager *m_cardsManager;
    Albums m_albums;
};

#endif // ALBUMSMODEL_H
