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
#include "cardssqlmanager.h"
#include "albumssqlmanager.h"
#include "albumssqlmodel.h"
class App: public QObject
{
    Q_OBJECT

    // Providers
    Q_PROPERTY(MainNetworkManager* mainNetworkManager READ getMainNetworkManager)
    Q_PROPERTY(ResourceImageProvider* resourceImageProvider READ getResourceImageProvider)

    // Managers
    Q_PROPERTY(AlbumsManager* albumsManager READ getAlbumsManager)
    Q_PROPERTY(CardsManager* cardsManager READ getCardsManager)
    Q_PROPERTY(CardsSQLManager* cardsSQLManager READ getCardsSQLManager)
    Q_PROPERTY(AlbumsSQLManager* albumsSQLManager READ getAlbumsSQLManager)

    // Models
    Q_PROPERTY(AlbumsModel* albumsModel READ getAlbumsModel)
    Q_PROPERTY(AlbumCardsModel* albumCardsModel READ getAlbumCardsModel)
    Q_PROPERTY(CardsSQLModel *cardsSQLModel READ getCardsSQLModel)
    Q_PROPERTY(AlbumsSQLModel *albumsSQLModel READ getAlbumsSQLModel)

public:
    explicit App(QObject *parent = 0);
    ~App();

    Q_INVOKABLE void currentAlbumChanged(int albID);
    Q_INVOKABLE void currentCardChanged(int crdID);
    Q_INVOKABLE void showAlbum(int albID);

    // Initializers
    void startInitializations();
    void startConnecttions();
    void startPopulating();

    // Getters
    MainNetworkManager* getMainNetworkManager() const;
    ResourceImageProvider* getResourceImageProvider() const;

    AlbumsManager* getAlbumsManager() const;
    CardsManager* getCardsManager() const;
    CardsSQLManager* getCardsSQLManager() const;
    AlbumsSQLManager* getAlbumsSQLManager() const;

    AlbumsModel* getAlbumsModel() const;
    AlbumCardsModel* getAlbumCardsModel() const;
    CardsSQLModel* getCardsSQLModel() const;
    AlbumsSQLModel* getAlbumsSQLModel() const;

public slots:
    void dataFromNetwork(QByteArray data);
    void refreshCardsSQLModel(int albID);
    void refreshCardsSQLModel();
    void refreshAlbumsSQLModel();

private:
    MainNetworkManager* networkManager;
    ResourceImageProvider* resourceImageProvider;

    AlbumsManager* albumsManager;
    CardsManager* cardsManager;
    CardsSQLManager* cardsSQLManager;
    AlbumsSQLManager* albumsSQLManager;

    AlbumsModel* albumsModel;
    AlbumCardsModel* albumCardsModel;
    CardsSQLModel *cardsSQLModel;
    AlbumsSQLModel* albumsSQLModel;

    QSqlDatabase db;

    int currentCardID;
    int currentAlbumID;

};

#endif // APP_H
