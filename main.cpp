#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QString>
#include <QQuickStyle>
#include <QQmlEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QtSql>
#include "app.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    QString serverName = "LOCALHOST\\SQLEXPRESS";
    QString dbName = "pokeManager";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
    db.setDatabaseName(dsn);

    if(db.open())
    {
//        // ALBUMS
//        qDebug() << "Opened!";
//        QString insertAlbumCommand = "INSERT INTO [dbo].[Albums]([albumMID],[albumName],[albumAdded],[albumEdited]) VALUES(:albumMID,:albumName,:albumAdded,:albumEdited);";

//        // Album 1
//        QSqlQuery qryAlbum;
//        qryAlbum.prepare(insertAlbumCommand);
//        qryAlbum.bindValue(":albumMID",1001);
//        qryAlbum.bindValue(":albumName","New Cards");
//        qryAlbum.bindValue(":albumAdded",QDateTime::currentDateTime());
//        qryAlbum.bindValue(":albumEdited",QDateTime::currentDateTime());
//        if(qryAlbum.exec()) { qDebug() << "Album 1 Inserted into Albums!"; }

//        // Album 2
//        QSqlQuery qryAlbum2;
//        qryAlbum2.prepare(insertAlbumCommand);
//        qryAlbum2.bindValue(":albumMID",1002);
//        qryAlbum2.bindValue(":albumName","Favorite Cards");
//        qryAlbum2.bindValue(":albumAdded",QDateTime::currentDateTime());
//        qryAlbum2.bindValue(":albumEdited",QDateTime::currentDateTime());
//        if(qryAlbum2.exec()) { qDebug() << "Album 2 Inserted into Albums!"; }

//        // Album 3
//        QSqlQuery qryAlbum3;
//        qryAlbum3.prepare(insertAlbumCommand);
//        qryAlbum3.bindValue(":albumMID",1003);
//        qryAlbum3.bindValue(":albumName","Old Cards");
//        qryAlbum3.bindValue(":albumAdded",QDateTime::currentDateTime());
//        qryAlbum3.bindValue(":albumEdited",QDateTime::currentDateTime());
//        if(qryAlbum3.exec()) { qDebug() << "Album 3 Inserted into Albums!"; }


//        // CARDS
//        QString insertCardCommand = "INSERT INTO [dbo].[Cards]([cardMID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited]) VALUES(:cardMID,:albumMID,:cardID,:name,:imageURL,:subtype,:supertype,:number,:artist,:rarity,:series,:setName,:setCode,:condition,:status,:loaded,:cardAdded,:cardEdited)";

//        // Card 1
//        QSqlQuery qryCard;
//        qryCard.prepare(insertCardCommand);
//        qryCard.bindValue(":cardMID",1001);
//        qryCard.bindValue(":albumMID",1001);
//        qryCard.bindValue(":cardID","xy7-54");
//        qryCard.bindValue(":name","Gardevoir");
//        qryCard.bindValue(":imageURL","https://s3.amazonaws.com/pokemontcg/xy7/54.png");
//        qryCard.bindValue(":subtype","Stage 2");
//        qryCard.bindValue(":supertype","Pokémon");
//        qryCard.bindValue(":number",54);
//        qryCard.bindValue(":artist","TOKIYA");
//        qryCard.bindValue(":rarity","Rare Holo");
//        qryCard.bindValue(":series","XY");
//        qryCard.bindValue(":setName","Ancient Origins");
//        qryCard.bindValue(":setCode","xy7");
//        qryCard.bindValue(":condition","Mint");
//        qryCard.bindValue(":status","In collection");
//        qryCard.bindValue(":loaded",false);
//        qryCard.bindValue(":cardAdded",QDateTime::currentDateTime());
//        qryCard.bindValue(":cardEdited",QDateTime::currentDateTime());
//        if(qryCard.exec()){ qDebug() << "Card 1 Inserted into Cards!"; }

//        // Card 2
//        QSqlQuery qryCard2;
//        qryCard2.prepare(insertCardCommand);
//        qryCard2.bindValue(":cardMID",1002);
//        qryCard2.bindValue(":albumMID",1001);
//        qryCard2.bindValue(":cardID","xy7-9");
//        qryCard2.bindValue(":name","Combee");
//        qryCard2.bindValue(":imageURL","https://s3.amazonaws.com/pokemontcg/xy7/9.png");
//        qryCard2.bindValue(":subtype","Basic");
//        qryCard2.bindValue(":supertype","Pokémon");
//        qryCard2.bindValue(":number",9);
//        qryCard2.bindValue(":artist","Sumiyoshi Kizuki");
//        qryCard2.bindValue(":rarity","Common");
//        qryCard2.bindValue(":series","XY");
//        qryCard2.bindValue(":setName","Ancient Origins");
//        qryCard2.bindValue(":setCode","xy7");
//        qryCard2.bindValue(":condition","Used");
//        qryCard2.bindValue(":status","Duplicate");
//        qryCard2.bindValue(":loaded",false);
//        qryCard2.bindValue(":cardAdded",QDateTime::currentDateTime());
//        qryCard2.bindValue(":cardEdited",QDateTime::currentDateTime());
//        if(qryCard2.exec()){ qDebug() << "Card 2 Inserted into Cards!"; }

//        // Card 3
//        QSqlQuery qryCard3;
//        qryCard3.prepare(insertCardCommand);
//        qryCard3.bindValue(":cardMID",1003);
//        qryCard3.bindValue(":albumMID",1002);
//        qryCard3.bindValue(":cardID","xy7-20");
//        qryCard3.bindValue(":name","Gyarados");
//        qryCard3.bindValue(":imageURL","https://s3.amazonaws.com/pokemontcg/xy7/20.png");
//        qryCard3.bindValue(":subtype","Stage 1");
//        qryCard3.bindValue(":supertype","Pokémon");
//        qryCard3.bindValue(":number",20);
//        qryCard3.bindValue(":artist","Shin Nagasawa");
//        qryCard3.bindValue(":rarity","Rare");
//        qryCard3.bindValue(":series","XY");
//        qryCard3.bindValue(":setName","Ancient Origins");
//        qryCard3.bindValue(":setCode","xy7");
//        qryCard3.bindValue(":condition","Almost Mint");
//        qryCard3.bindValue(":status","Duplicate");
//        qryCard3.bindValue(":loaded",false);
//        qryCard3.bindValue(":cardAdded",QDateTime::currentDateTime());
//        qryCard3.bindValue(":cardEdited",QDateTime::currentDateTime());
//        if(qryCard3.exec()){ qDebug() << "Card 3 Inserted into Cards!"; }

//        // Card 4
//        QSqlQuery qryCard4;
//        qryCard4.prepare(insertCardCommand);
//        qryCard4.bindValue(":cardMID",1004);
//        qryCard4.bindValue(":albumMID",1003);
//        qryCard4.bindValue(":cardID","xy7-28");
//        qryCard4.bindValue(":name","M Ampharos-EX");
//        qryCard4.bindValue(":imageURL","https://s3.amazonaws.com/pokemontcg/xy7/28.png");
//        qryCard4.bindValue(":subtype","MEGA");
//        qryCard4.bindValue(":supertype","Pokémon");
//        qryCard4.bindValue(":number",28);
//        qryCard4.bindValue(":artist","5ban Graphics");
//        qryCard4.bindValue(":rarity","Rare Holo EX");
//        qryCard4.bindValue(":series","XY");
//        qryCard4.bindValue(":setName","Ancient Origins");
//        qryCard4.bindValue(":setCode","xy7");
//        qryCard4.bindValue(":condition","Mint");
//        qryCard4.bindValue(":status","In Collection");
//        qryCard4.bindValue(":loaded",true);
//        qryCard4.bindValue(":cardAdded",QDateTime::currentDateTime());
//        qryCard4.bindValue(":cardEdited",QDateTime::currentDateTime());
//        if(qryCard4.exec()){ qDebug() << "Card 4 Inserted into Cards!"; }

//        // Card 5
//        QSqlQuery qryCard5;
//        qryCard5.prepare(insertCardCommand);
//        qryCard5.bindValue(":cardMID",1005);
//        qryCard5.bindValue(":albumMID",1003);
//        qryCard5.bindValue(":cardID","xy7-33");
//        qryCard5.bindValue(":name","Claydol");
//        qryCard5.bindValue(":imageURL","https://s3.amazonaws.com/pokemontcg/xy7/33.png");
//        qryCard5.bindValue(":subtype","Stage 1");
//        qryCard5.bindValue(":supertype","Pokémon");
//        qryCard5.bindValue(":number",33);
//        qryCard5.bindValue(":artist","Satoshi Shirai");
//        qryCard5.bindValue(":rarity","Rare");
//        qryCard5.bindValue(":series","XY");
//        qryCard5.bindValue(":setName","Ancient Origins");
//        qryCard5.bindValue(":setCode","xy7");
//        qryCard5.bindValue(":condition","Worn down");
//        qryCard5.bindValue(":status","Needs replacement");
//        qryCard5.bindValue(":loaded",false);
//        qryCard5.bindValue(":cardAdded",QDateTime::currentDateTime());
//        qryCard5.bindValue(":cardEdited",QDateTime::currentDateTime());
//        if(qryCard5.exec()){ qDebug() << "Card 5 Inserted into Cards!"; }

//        qDebug() << "\nDone Inserting Albums!\n";


        // VIEW ALBUMS
        qDebug() << "\nShowing Albums!";
        QSqlQuery qryViewAlbums;
        if(qryViewAlbums.exec("SELECT [albumMID],[albumName],[albumAdded],[albumEdited] FROM [dbo].[Albums]"))
        {
            int count = 1;
            while(qryViewAlbums.next())
            {
                qDebug() << "\nShowing Album " << count << ":";
                qDebug() << "Album MID: " << qryViewAlbums.value(0).toString();
                qDebug() << "Album name: " << qryViewAlbums.value(1).toString();
                qDebug() << "Album added on: " << qryViewAlbums.value(2).toString();
                qDebug() << "Album last edited: " << qryViewAlbums.value(3).toString();
            }
        }

        // VIEW CARDS
        qDebug() << "\nShowing Cards!";
        QSqlQuery qryViewCards;
        if(qryViewCards.exec("SELECT [cardMID],[albumMID],[cardID],[name],[imageURL],[subtype],[supertype],[number],[artist],[rarity],[series],[setName],[setCode],[condition],[status],[loaded],[cardAdded],[cardEdited] FROM [dbo].[Cards]"))
        {
            int count = 1;
            while(qryViewCards.next())
            {
                qDebug() << "\nShowing Card " << count << ":";
                qDebug() << "Card MID: " << qryViewCards.value(0).toString();
                qDebug() << "In Album MID: " << qryViewCards.value(1).toString();
                qDebug() << "Card ID: " << qryViewCards.value(2).toString();
                qDebug() << "card name: " << qryViewCards.value(3).toString();
                qDebug() << "card image URL: " << qryViewCards.value(4).toString();
                qDebug() << "card subtype: " << qryViewCards.value(5).toString();
                qDebug() << "card supertype: " << qryViewCards.value(6).toString();
                qDebug() << "card number: " << qryViewCards.value(7).toString();
                qDebug() << "card artist: " << qryViewCards.value(8).toString();
                qDebug() << "card rarity: " << qryViewCards.value(9).toString();
                qDebug() << "card series: " << qryViewCards.value(10).toString();
                qDebug() << "card setName: " << qryViewCards.value(11).toString();
                qDebug() << "card setCode: " << qryViewCards.value(12).toString();
                qDebug() << "card condition: " << qryViewCards.value(13).toString();
                qDebug() << "card status: " << qryViewCards.value(14).toString();
                qDebug() << "card loaded: " << qryViewCards.value(15).toString();
                qDebug() << "card added on: " << qryViewCards.value(16).toString();
                qDebug() << "card last edited: " << qryViewCards.value(17).toString();
            }
        }


        qDebug() << "Closing!";
        db.close();
    }
    else
    {
        qDebug() << "Error: " << db.lastError();
    }

    // Core classes
    qmlRegisterType<App>("PokeApp.Classes.Core", 1, 0, "App");

    App mainApp;
    QQmlApplicationEngine engine;


    // Context properties
    engine.addImageProvider(QLatin1String("resourceImageProvider"), mainApp.getResourceImageProvider());
    QQmlContext *ctxt1 = engine.rootContext();
    ctxt1->setContextProperty("mainApp", &mainApp);
    QQmlContext *ctxt2 = engine.rootContext();
    ctxt2->setContextProperty("MyModel", mainApp.getAlbumCardsModel());
    QQmlContext *ctxt3 = engine.rootContext();
    ctxt3->setContextProperty("MyAlbumsModel", mainApp.getAlbumsModel());



    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
