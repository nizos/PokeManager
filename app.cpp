#include "app.h"

// Default Constructor
App::App(QObject *parent): QObject(parent)
{
    /// Initialize
    // Providers
    this->networkManager = new MainNetworkManager();
    this->resourceImageProvider = new ResourceImageProvider();

    // Managers
    this->albumsManager = new AlbumsManager();
    this->cardsManager = new CardsManager();

    // Models
    this->albumsModel = new AlbumsModel();
    this->albumCardsModel = new AlbumCardsModel();
    this->cardsSQLModel = new CardsSQLModel();

    /// Connect
    // Database
    QString serverName = "LOCALHOST\\SQLEXPRESS";
    QString dbName = "pokeManager";
    this->db = QSqlDatabase::addDatabase("QODBC");
    this->db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
    db.setDatabaseName(dsn);
    if(db.open()){qDebug() << "Connection to database opened.";}
    else{qDebug() << "ERROR: Couldn't connect to database!\n" << db.lastError();}


    // Register Types
    qmlRegisterType<ResourceImageProvider>("PokeApp.Classes.Core", 1, 0, "resourceImageProvider");
    qmlRegisterType<AlbumsManager>("PokeApp.Classes.Core", 1, 0, "AlbumsManager");
    qmlRegisterType<CardsManager>("PokeApp.Classes.Core", 1, 0, "CardsManager");
    qmlRegisterType<AlbumCardsModel>("PokeApp.Classes.Core", 1, 0, "AlbumCardsModel");
    qmlRegisterType<AlbumsModel>("PokeApp.Classes.Core", 1, 0, "AlbumsModel");
    qmlRegisterType<CardsSQLModel>("PokeApp.Classes.Core", 1, 0, "cardsSQLModel");


    // Connect classes
    this->albumsManager->setCardsManager(cardsManager);
    this->albumsModel->setAlbumsManager(albumsManager);
    this->albumsModel->setCardsManager(cardsManager);
    this->albumCardsModel->setAlbumsManager(albumsManager);
    this->albumCardsModel->setCardsManager(cardsManager);
    this->resourceImageProvider->setSQLDatabase(&db);
    this->cardsSQLModel->setQuery("SELECT [cardMID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards]",db);

    /// Signals & Slots
    // AlbumCards Model
    connect(albumsManager, SIGNAL(albumAdded(int)),albumCardsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),albumCardsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)), albumCardsModel, SLOT(onCardUpdated(int,QString)));

    // Albums Model
    connect(albumsManager, SIGNAL(albumAdded(int)),albumsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),albumsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)),albumsModel, SLOT(onCardUpdated(int,QString)));

    /// Populate
    // Albums
    albumsManager->addAlbum("My Cards");
    albumsManager->addAlbum("My Favorites");

    // Cards
    albumsManager->addCard(1001,"xy7-51");
    albumsManager->addCard(1001,"xy7-52");
    albumsManager->addCard(1001,"xy7-53");
    albumsManager->addCard(1001,"xy7-54");
    albumsManager->addCard(1002,"xy7-55");
    albumsManager->addCard(1002,"xy7-56");

    // Views
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

CardsSQLModel* App::getCardsSQLModel() const
{
    return this->cardsSQLModel;
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

App::~App()
{
    this->db.close();
    qDebug() << "Connection to database closed.";
}
