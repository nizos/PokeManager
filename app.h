#ifndef APP_H
#define APP_H
#include <QtQml>
#include <QObject>
#include <QDebug>
#include <QPixmap>
#include "mainnetworkmanager.h"
#include "albumsmanager.h"
#include "albumcardsmodel.h"
#include "abstractcardmodel.h"
#include "abstractalbummodel.h"
#include "albumsmodel.h"


class App: public QObject
{
    Q_OBJECT
    Q_PROPERTY(AlbumsManager* albumsManager READ albumsManager)
    Q_PROPERTY(CardsManager* cardsManager READ cardsManager)
    Q_PROPERTY(AlbumsModel* albumsModel READ albumsModel)
    Q_PROPERTY(AlbumCardsModel* albumCardsModel READ albumCardsModel)
    Q_PROPERTY(MainNetworkManager* mainNetworkManager READ mainNetworkManager)

public:
    explicit App(QObject *parent = 0);

    // Getters
    AlbumsManager* albumsManager() const;
    CardsManager* cardsManager() const;
    AlbumsModel* albumsModel() const;
    AlbumCardsModel* albumCardsModel() const;
    MainNetworkManager* mainNetworkManager() const;

public slots:
    void dataFromNetwork(QByteArray data);

private:
    AlbumsManager* m_albumsManager;
    CardsManager* m_cardsManager;
    AlbumsModel* m_albumsModel;
    AlbumCardsModel* m_albumCardsModel;
    MainNetworkManager* m_networkManager;
};

#endif // APP_H
