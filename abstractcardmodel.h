#ifndef ABSTRACTCARDMODEL_H
#define ABSTRACTCARDMODEL_H
#include <QString>
#include <QObject>
#include <QAbstractListModel>
#include "cardsmanager.h"
#include "album.h"
#include "card.h"


class AbstractCardModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AlbumRoles { CardIDRole = Qt::UserRole + 1, CardMIDRole, NameRole, ImageURLRole, SubtypeRole, SupertypeRole, NumberRole, ArtistRole, RarityRole, SeriesRole, SetRole,  SetCodeRole, ConditionRole, StatusRole};

    AbstractCardModel(QObject *parent = 0);
    AbstractCardModel(CardsManager *cardManagerPointer, QObject *parent = 0);

    void setCardsManager(CardsManager *cardManagerPointer);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
    virtual Card cardForIndex(const QModelIndex &index) const = 0;

protected:
    CardsManager *m_cardManagerPointer;
};

#endif //ABSTRACTCARDMODEL_H
