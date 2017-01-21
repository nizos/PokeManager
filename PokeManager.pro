
QT += qml quick core sql gui widgets network quickcontrols2

LIBS += -LC:/OpenSSL-Win64/lib -llibeay32
LIBS += -LC:/OpenSSL-Win64/lib -lssleay32
INCLUDEPATH += C:/OpenSSL-Win64/include

CONFIG += c++11

SOURCES += main.cpp \
    abstractalbummodel.cpp \
    abstractcardmodel.cpp \
    album.cpp \
    albumcardsmodel.cpp \
    albumsmanager.cpp \
    albumsmodel.cpp \
    app.cpp \
    card.cpp \
    cardsmanager.cpp \
    mainnetworkmanager.cpp \
    albums.cpp \
    albumcardsdelegate.cpp \
    resourceimageprovider.cpp \
    imagehandler.cpp \
    cardssqlmodel.cpp \
    cardssqlmanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractalbummodel.h \
    abstractcardmodel.h \
    album.h \
    albumcardsmodel.h \
    albumsmanager.h \
    albumsmodel.h \
    app.h \
    card.h \
    cardsmanager.h \
    mainnetworkmanager.h \
    albums.h \
    albumcardsdelegate.h \
    resourceimageprovider.h \
    imagehandler.h \
    cardssqlmodel.h \
    cardssqlmanager.h

DISTFILES +=
