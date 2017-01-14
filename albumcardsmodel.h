#ifndef ALBUMCARDSMODEL_H
#define ALBUMCARDSMODEL_H
#include <QObject>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QVector>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QModelIndex>
#include "abstractcardmodel.h"
#include "albumsmanager.h"


class AlbumCardsModel : public AbstractCardModel
{
    Q_OBJECT
public:
    enum AlbumRoles { AlbumNameRole = Qt::UserRole + 1};
    AlbumCardsModel(QObject *parent = 0);
    AlbumCardsModel(AlbumsManager *albumsManager, CardsManager *cardsManager, QObject *parent = 0);

    Q_INVOKABLE void showAlbum(const int albumId);
    int rowCount(const QModelIndex &parent) const;
    void setAlbumsManager(AlbumsManager *albumsManager);
    void setCardsManager(CardsManager *cardsManager);

protected:
    Card cardForIndex(const QModelIndex &index) const;

signals:
    void cardAdded(const int nrOfCards);

private slots:
    void onAlbumAdded(const int albumId);
    void onCardAdded(const int albumId, const QString cMID);

private:
    AlbumsManager *m_albumsManager;
    CardsManager *m_cardsManager;
    Album m_album;
};

#endif // ALBUMCARDSMODEL_H
