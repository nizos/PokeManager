#include "app.h"

// Default Constructor
App::App(QObject *parent): QObject(parent)
{
    /// Initialize
    this->currentAlbumID = 1;
    this->currentCardID = 1;

    // Providers
    this->networkManager = new MainNetworkManager();
    this->resourceImageProvider = new ResourceImageProvider();

    // Managers
    this->albumsManager = new AlbumsManager();
    this->cardsManager = new CardsManager();
    this->cardsSQLManager = new CardsSQLManager();
    this->albumsSQLManager = new AlbumsSQLManager();

    // Models
    this->albumsModel = new AlbumsModel();
    this->albumCardsModel = new AlbumCardsModel();
    this->cardsSQLModel = new CardsSQLModel();
    this->albumsSQLModel = new AlbumsSQLModel();

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
    qmlRegisterType<CardsSQLModel>("PokeApp.Classes.Core", 1, 0, "CardsSQLModel");
    qmlRegisterType<AlbumsSQLModel>("PokeApp.Classes.Core", 1, 0, "AlbumsSQLModel");
    qmlRegisterType<AlbumsSQLManager>("PokeApp.Classes.Core", 1, 0, "AlbumsSQLManager");

    // Connect classes
    this->albumsSQLManager->setDB(&db);
    this->albumsSQLManager->setCardsSQLManager(cardsSQLManager);
    this->cardsSQLManager->setDB(&db);
    this->cardsSQLManager->setResourceImageProvider(resourceImageProvider);
    this->albumsManager->setCardsManager(cardsManager);
    this->albumsModel->setAlbumsManager(albumsManager);
    this->albumsModel->setCardsManager(cardsManager);
    this->albumCardsModel->setAlbumsManager(albumsManager);
    this->albumCardsModel->setCardsManager(cardsManager);
    this->resourceImageProvider->setSQLDatabase(&db);

    this->albumsSQLModel->setQuery("SELECT [ID],[albumName],[albumAdded],[albumEdited] FROM [dbo].[Albums2]",db);

    this->cardsSQLModel->setQuery("SELECT [ID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards3]",db);

    /// Signals & Slots
    // AlbumCards Model
    connect(albumsManager, SIGNAL(albumAdded(int)),albumCardsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),albumCardsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)), albumCardsModel, SLOT(onCardUpdated(int,QString)));

    // Albums Model
    connect(albumsManager, SIGNAL(albumAdded(int)),albumsModel, SLOT(onAlbumAdded(int)));
    connect(albumsManager, SIGNAL(cardAdded(int,QString)),albumsModel, SLOT(onCardAdded(int,QString)));
    connect(cardsManager, SIGNAL(cardUpdated(int,QString)),albumsModel, SLOT(onCardUpdated(int,QString)));

    connect(resourceImageProvider, SIGNAL(cardUpdated(QString)), this, SLOT(refreshCardsSQLModel()));
    connect(resourceImageProvider, SIGNAL(cardAdded(QString)), this, SLOT(refreshCardsSQLModel()));
    connect(resourceImageProvider, SIGNAL(cardRemoved(QString)), this, SLOT(refreshCardsSQLModel()));

    // Cards SQL Manager
    connect(cardsSQLManager, SIGNAL(cardAdded(int,int)), this, SLOT(refreshCardsSQLModel(int)));
    connect(cardsSQLManager, SIGNAL(cardAdded(int,int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(cardsSQLManager, SIGNAL(cardUpdated(int,int)), this, SLOT(refreshCardsSQLModel(int)));

    connect(cardsSQLManager, SIGNAL(cardRemoved(int,int)), this, SLOT(refreshCardsSQLModel(int)));
    connect(cardsSQLManager, SIGNAL(cardRemoved(int,int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(cardsSQLManager, SIGNAL(albumUpdated(int)), this, SLOT(refreshCardsSQLModel(int)));
    connect(cardsSQLManager, SIGNAL(albumUpdated(int)), this, SLOT(refreshAlbumsSQLModel()));

    // Albums SQL Manager
    connect(albumsSQLManager, SIGNAL(albumAdded(int)), this, SLOT(refreshCardsSQLModel()));
    connect(albumsSQLManager, SIGNAL(albumAdded(int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(albumsSQLManager, SIGNAL(albumUpdated(int)), this, SLOT(refreshCardsSQLModel()));
    connect(albumsSQLManager, SIGNAL(albumUpdated(int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(albumsSQLManager, SIGNAL(albumRemoved(int)), this, SLOT(refreshCardsSQLModel()));
    connect(albumsSQLManager, SIGNAL(albumRemoved(int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(albumsSQLManager, SIGNAL(cardAdded(int,int)), this, SLOT(refreshCardsSQLModel(int)));
    connect(albumsSQLManager, SIGNAL(cardAdded(int,int)), this, SLOT(refreshAlbumsSQLModel()));

    connect(albumsSQLManager, SIGNAL(cardUpdated(int,int)), this, SLOT(refreshCardsSQLModel(int)));

    connect(albumsSQLManager, SIGNAL(cardRemoved(int,int)), this, SLOT(refreshCardsSQLModel(int)));
    connect(albumsSQLManager, SIGNAL(cardRemoved(int,int)), this, SLOT(refreshAlbumsSQLModel()));

//    connect(cardsSQLManager, SIGNAL(cardRemoved(int)), this, SLOT(refreshCardsSQLModel()));

    /// Populate
    // Albums
//    albumsManager->addAlbum("My Cards");
//    albumsManager->addAlbum("My Favorites");

    // Cards
//    albumsManager->addCard(1001,"xy7-51");
//    albumsManager->addCard(1001,"xy7-52");
//    albumsManager->addCard(1001,"xy7-53");
//    albumsManager->addCard(1001,"xy7-54");
//    albumsManager->addCard(1002,"xy7-55");
//    albumsManager->addCard(1002,"xy7-56");

    // Views
//    albumCardsModel->showAlbum(1001);
//    albumsModel->showAlbums();
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

CardsSQLManager* App::getCardsSQLManager() const
{
    return this->cardsSQLManager;
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

AlbumsSQLModel* App::getAlbumsSQLModel() const
{
    return this->albumsSQLModel;
}

AlbumsSQLManager* App::getAlbumsSQLManager() const
{
    return this->albumsSQLManager;
}

void App::showAlbum(int albID)
{
    qDebug() << "Showing Album: " << albID;
    this->cardsSQLModel->setQuery("SELECT [ID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards3]", db);
}

void App::refreshCardsSQLModel(int albID)
{
    qDebug() << "Refreshing CardsSQLModel.";
    this->cardsSQLModel->setQuery("SELECT [ID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards3]", db);
}

void App::refreshCardsSQLModel()
{
    qDebug() << "Refreshing CardsSQLModel.";
    this->cardsSQLModel->setQuery("SELECT [ID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards3]", db);
}

void App::refreshAlbumsSQLModel()
{
    qDebug() << "Refreshing AlbumsSQLModel.";
    this->albumsSQLModel->setQuery("SELECT [ID],[albumName],[albumAdded],[albumEdited] FROM [dbo].[Albums2]",db);
}

void App::currentAlbumChanged(int albID)
{
    this->currentAlbumID = albID;
}

void App::currentCardChanged(int crdID)
{
    this->currentCardID = crdID;
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
