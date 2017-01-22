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
#include "cardssqlmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    // Core classes
    qmlRegisterType<App>("PokeApp.Classes.Core", 1, 0, "App");

    App mainApp;
    QQmlApplicationEngine engine;

    // Context properties
    engine.addImageProvider(QLatin1String("rip"), mainApp.getResourceImageProvider());
    QQmlContext *ctxt0 = engine.rootContext();
    ctxt0->setContextProperty("cardsSQLModel",  mainApp.getCardsSQLModel());
    QQmlContext *ctxt1 = engine.rootContext();
    ctxt1->setContextProperty("mainApp", &mainApp);
    QQmlContext *ctxt2 = engine.rootContext();
    ctxt2->setContextProperty("myModel", mainApp.getAlbumCardsModel());
    QQmlContext *ctxt3 = engine.rootContext();
    ctxt3->setContextProperty("myAlbumsModel", mainApp.getAlbumsModel());
    QQmlContext *ctxt4 = engine.rootContext();
    ctxt4->setContextProperty("cardsSQLManager", mainApp.getCardsSQLManager());
    QQmlContext *ctxt5 = engine.rootContext();
    ctxt5->setContextProperty("albumsSQLManager", mainApp.getAlbumsSQLManager());
    QQmlContext *ctxt6 = engine.rootContext();
    ctxt6->setContextProperty("albumsSQLModel",  mainApp.getAlbumsSQLModel());

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    return app.exec();
}
