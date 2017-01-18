#include "app.h"

// Default Constructor
App::App(QObject *parent): QObject(parent)
{
    this->resourceImageProvider = new ResourceImageProvider();
    this->albumsManager = new AlbumsManager();
    this->cardsManager = new CardsManager();
    this->albumsModel = new AlbumsModel();
    this->albumCardsModel = new AlbumCardsModel();
    this->networkManager = new MainNetworkManager();

    this->albumsManager->setCardsManager(cardsManager);
    this->albumsModel->setAlbumsManager(albumsManager);
    this->albumsModel->setCardsManager(cardsManager);
    this->albumCardsModel->setAlbumsManager(albumsManager);
    this->albumCardsModel->setCardsManager(cardsManager);

    qmlRegisterType<ResourceImageProvider>("PokeApp.Classes.Core", 1, 0, "resourceImageProvider");
    qmlRegisterType<AlbumsManager>("PokeApp.Classes.Core", 1, 0, "AlbumsManager");
    qmlRegisterType<CardsManager>("PokeApp.Classes.Core", 1, 0, "CardsManager");
    qmlRegisterType<AlbumCardsModel>("PokeApp.Classes.Core", 1, 0, "AlbumCardsModel");
    qmlRegisterType<AlbumsModel>("PokeApp.Classes.Core", 1, 0, "AlbumsModel");

    // AlbumCards Model
    connect(albumsManager, SIGNAL(albumAdded(int)),
                         albumCardsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),
                         albumCardsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)),
                         albumCardsModel, SLOT(onCardUpdated(int,QString)));

    // Albums Model
    connect(albumsManager, SIGNAL(albumAdded(int)),
                         albumsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),
                         albumsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)),
                         albumsModel, SLOT(onCardUpdated(int,QString)));



    albumsManager->addAlbum("My Cards");
    albumsManager->addAlbum("My Favorites");

    albumsManager->addCard(1001,"xy7-5");
    albumsManager->addCard(1001,"xy7-6");
    albumsManager->addCard(1001,"xy7-7");
    albumsManager->addCard(1001,"xy7-8");

    albumsManager->addCard(1002,"xy7-13");
    albumsManager->addCard(1002,"xy7-14");

    albumCardsModel->showAlbum(1001);
    albumsModel->showAlbums();
}

//// Getters
ResourceImageProvider* App::getResourceImageProvider() const
{
    return this->resourceImageProvider;
}

AlbumsManager* App::getAlbumsManager() const
{
    return this->albumsManager;
}

CardsManager* App::getCardsManager() const
{
    return this->cardsManager;
}

AlbumsModel* App::getAlbumsModel() const
{
    return this->albumsModel;
}

AlbumCardsModel* App::getAlbumCardsModel() const
{
    return this->albumCardsModel;
}

MainNetworkManager* App::getMainNetworkManager() const
{
    return this->networkManager;
}

void App::dataFromNetwork(QByteArray data)
{
//    QString val = data;
//    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
//    QJsonObject sett2 = d.object();
//    QJsonValue value = sett2.value(QString("card"));
//    QJsonObject item = value.toObject();
//    QString imgUrl = item["imageUrl"].toString();
//    imgUrl = ("http://s3.amazonaws.com/pokemontcg/xy7/54.png");

//    networkManager->makeRequest(imgUrl);
//    QPixmap img;
//    if(img.loadFromData(data,"PNG"))
//    {
//         qDebug() << "Image loaded";
//    }
}
