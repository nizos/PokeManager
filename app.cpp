#include "app.h"

// Default Constructor
App::App(QObject *parent): QObject(parent)
{
    this->m_albumsManager = new AlbumsManager();
    this->m_cardsManager = new CardsManager();
    this->m_albumsModel = new AlbumsModel();
    this->m_albumCardsModel = new AlbumCardsModel();
    this->m_networkManager = new MainNetworkManager();


    this->m_albumsManager->setCardsManager(m_cardsManager);
    this->m_albumsModel->setAlbumsManager(m_albumsManager);
    this->m_albumsModel->setCardsManager(m_cardsManager);
    this->m_albumCardsModel->setAlbumsManager(m_albumsManager);
    this->m_albumCardsModel->setCardsManager(m_cardsManager);

    qmlRegisterType<AlbumsManager>("PokeApp.Classes.Core", 1, 0, "AlbumsManager");
    qmlRegisterType<CardsManager>("PokeApp.Classes.Core", 1, 0, "CardsManager");
    qmlRegisterType<AlbumCardsModel>("PokeApp.Classes.Core", 1, 0, "AlbumCardsModel");
    qmlRegisterType<AlbumsModel>("PokeApp.Classes.Core", 1, 0, "AlbumsModel");

    connect(m_albumsManager, SIGNAL(albumAdded(int)),
                         m_albumCardsModel, SLOT(onAlbumAdded(int)));
    connect(m_albumsManager, SIGNAL(cardAdded(int,QString)),
                         m_albumCardsModel, SLOT(onCardAdded(int,QString)));

    connect(m_albumsManager, SIGNAL(albumAdded(int)),
                         m_albumsModel, SLOT(onAlbumAdded(int)));
    connect(m_albumsManager, SIGNAL(cardAdded(int,QString)),
                         m_albumsModel, SLOT(onCardAdded(int,QString)));


    connect(m_networkManager,SIGNAL(readyData(QByteArray)),
            this,SLOT(dataFromNetwork(QByteArray)));

    m_albumsManager->addAlbum("My Cards");
    m_albumsManager->addAlbum("My Favorites");

    m_albumsManager->addCard(1001,"xy7-5");
    m_albumsManager->addCard(1001,"xy7-6");
    m_albumsManager->addCard(1001,"xy7-7");
    m_albumsManager->addCard(1001,"xy7-8");

    m_albumsManager->addCard(1002,"xy7-13");
    m_albumsManager->addCard(1002,"xy7-14");

    m_albumCardsModel->showAlbum(1001);
    m_albumsModel->showAlbums();
}

//// Getters
AlbumsManager* App::albumsManager() const
{
    return this->m_albumsManager;
}

CardsManager* App::cardsManager() const
{
    return this->m_cardsManager;
}

AlbumsModel* App::albumsModel() const
{
    return this->m_albumsModel;
}

AlbumCardsModel* App::albumCardsModel() const
{
    return this->m_albumCardsModel;
}

MainNetworkManager* App::mainNetworkManager() const
{
    return this->m_networkManager;
}

void App::dataFromNetwork(QByteArray data)
{
    QString val = data;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("card"));
    QJsonObject item = value.toObject();
    QString imgUrl = item["imageUrl"].toString();
    imgUrl = ("http://s3.amazonaws.com/pokemontcg/xy7/54.png");

    m_networkManager->makeRequest(imgUrl);
    QPixmap img;
    if(img.loadFromData(data,"PNG"))
    {
         qDebug() << "Image loaded";
    }
}
