#ifndef APP_H
#define APP_H
#include <QtQml>
#include <QObject>
#include <QDebug>
#include <QPixmap>
#include "resourceimageprovider.h"
#include "mainnetworkmanager.h"
#include "albumsmanager.h"
#include "albumcardsmodel.h"
#include "abstractcardmodel.h"
#include "abstractalbummodel.h"
#include "albumsmodel.h"


class App: public QObject
{
    Q_OBJECT
    Q_PROPERTY(ResourceImageProvider* resourceImageProvider READ getResourceImageProvider)
    Q_PROPERTY(AlbumsManager* albumsManager READ getAlbumsManager)
    Q_PROPERTY(CardsManager* cardsManager READ getCardsManager)
    Q_PROPERTY(AlbumsModel* albumsModel READ getAlbumsModel)
    Q_PROPERTY(AlbumCardsModel* albumCardsModel READ getAlbumCardsModel)
    Q_PROPERTY(MainNetworkManager* mainNetworkManager READ getMainNetworkManager)

public:
    explicit App(QObject *parent = 0);

    // Getters
    ResourceImageProvider* getResourceImageProvider() const;
    AlbumsManager* getAlbumsManager() const;
    CardsManager* getCardsManager() const;
    AlbumsModel* getAlbumsModel() const;
    AlbumCardsModel* getAlbumCardsModel() const;
    MainNetworkManager* getMainNetworkManager() const;

public slots:
    void dataFromNetwork(QByteArray data);

private:
    ResourceImageProvider* resourceImageProvider;
    AlbumsManager* albumsManager;
    CardsManager* cardsManager;
    AlbumsModel* albumsModel;
    AlbumCardsModel* albumCardsModel;
    MainNetworkManager* networkManager;
};

#endif // APP_H
