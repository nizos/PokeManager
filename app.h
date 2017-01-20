#ifndef APP_H
#define APP_H
#include <QtQml>
#include <QSqlError>
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
#include "cardssqlmodel.h"

class App: public QObject
{
    Q_OBJECT

    // Providers
    Q_PROPERTY(MainNetworkManager* mainNetworkManager READ getMainNetworkManager)
    Q_PROPERTY(ResourceImageProvider* resourceImageProvider READ getResourceImageProvider)

    // Managers
    Q_PROPERTY(AlbumsManager* albumsManager READ getAlbumsManager)
    Q_PROPERTY(CardsManager* cardsManager READ getCardsManager)

    // Models
    Q_PROPERTY(AlbumsModel* albumsModel READ getAlbumsModel)
    Q_PROPERTY(AlbumCardsModel* albumCardsModel READ getAlbumCardsModel)
    Q_PROPERTY(CardsSQLModel *cardsSQLModel READ getCardsSQLModel)

public:
    explicit App(QObject *parent = 0);
    ~App();

    // Initializers
    void startInitializations();
    void startConnecttions();
    void startPopulating();

    // Getters
    MainNetworkManager* getMainNetworkManager() const;
    ResourceImageProvider* getResourceImageProvider() const;

    AlbumsManager* getAlbumsManager() const;
    CardsManager* getCardsManager() const;

    AlbumsModel* getAlbumsModel() const;
    AlbumCardsModel* getAlbumCardsModel() const;
    CardsSQLModel* getCardsSQLModel() const;

public slots:
    void dataFromNetwork(QByteArray data);

private:
    MainNetworkManager* networkManager;
    ResourceImageProvider* resourceImageProvider;

    AlbumsManager* albumsManager;
    CardsManager* cardsManager;

    AlbumsModel* albumsModel;
    AlbumCardsModel* albumCardsModel;
    CardsSQLModel *cardsSQLModel;

    QSqlDatabase db;

};

#endif // APP_H
