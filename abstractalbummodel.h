#ifndef ABSTRACTALBUMMODEL_H
#define ABSTRACTALBUMMODEL_H
#include <QString>
#include <QObject>
#include <QAbstractListModel>
#include "albumsmanager.h"
#include "album.h"

class AbstractAlbumModel: public QAbstractListModel
{
    Q_OBJECT
public:
    // AlbumRoles
    enum AlbumRoles { AlbumNameRole = Qt::UserRole + 1, AlbumIDRole, CardsInAlbumRole, CardOneInAlbumRole, CardTwoInAlbumRole, CardThreeInAlbumRole, CardFourInAlbumRole};

    // Default Constructor
    AbstractAlbumModel(QObject* parent = 0);

    // Overloaded Constructor
    AbstractAlbumModel(AlbumsManager *m_albumsManager, QObject *parent = 0);

    void setAlbumsManager(AlbumsManager *m_albumsManager);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

    virtual Album albumForIndex(const QModelIndex& index) const = 0;

protected:
    AlbumsManager *m_albumsManager;
};

#endif // ABSTRACTALBUMMODEL_H
