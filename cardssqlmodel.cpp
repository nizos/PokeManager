#include "cardssqlmodel.h"
#include <QSqlRecord>
#include <QSqlField>

//const char* CardsSQLModel::COLUMN_NAMES[] = {
//    "cardMID",
//    "albumMID",
//    "cardID",
//    "name",
//    "imageURL",
//    "subtype",
//    "supertype",
//    "number",
//    "artist",
//    "rarity",
//    "series",
//    "setName",
//    "setCode",
//    "condition",
//    "status",
//    "loaded",
//    "cardAdded",
//    "cardEdited",
//    NULL
//};
//const char* CardsSQLModel::SQL_SELECT =
//    " Albums.albumMID, Albums.albumName, Cards.cardMID, Cards.albumMID, Cards.cardID, Cards.name, Cards.imageURL, Cards.subtype, Cards.supertype, Cards.number, Cards.artist, Cards.rarity, Cards.series, Cards.setName, Cards.setCode, Cards.condition, Cards.status, Cards.loaded, Cards.cardAdded, Cards.cardEdited"
//    "  FROM Cards"
//    " JOIN Albums ON Albums.albumMID = Cards.albumMID";



CardsSQLModel::CardsSQLModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

void CardsSQLModel::setQuery(const QString &query, const QSqlDatabase &db)
{
    QSqlQueryModel::setQuery(query, db);
    generateRoleNames();
}

void CardsSQLModel::setQuery(const QSqlQuery & query)
{
    QSqlQueryModel::setQuery(query);
    generateRoleNames();
}

void CardsSQLModel::generateRoleNames()
{
    m_roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        m_roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
}

QVariant CardsSQLModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

CardsSQLModel::~CardsSQLModel()
{

}

//QHash<int, QByteArray> CardsSQLModel::roleNames() const
//{
//       QHash<int, QByteArray> roles;
//       roles[CardMIDRole] = "cardMID";
//       roles[CardAlbumMIDRole] = "albumMID";
//       roles[CardIDRole] = "cardID";
//       roles[CardNameRole] = "name";
//       roles[CardImageURLRole] = "imageURL";
//       roles[CardSubtypeRole] = "subtype";
//       roles[CardSupertypeRole] = "supertype";
//       roles[CardNumberRole] = "number";
//       roles[CardArtistRole] = "artist";
//       roles[CardRarityRole] = "rarity";
//       roles[CardSeriesRole] = "series";
//       roles[CardSetNameRole] = "setName";
//       roles[CardSetCodeRole] = "setCode";
//       roles[CardStatusRole] = "status";
//       roles[CardConditionRole] = "condition";
//       roles[CardAddedRole] = "added";
//       roles[CardEditedRole] = "edited";
//       return roles;
//}


//QVariant CardsSQLModel::data(const QModelIndex &index, int role) const
//{
//    QVariant value = QSqlQueryModel::data(index, role);
//    if(role < Qt::UserRole)
//    {
//        value = QSqlQueryModel::data(index, role);
//    }
//    else
//    {
//        int columnIdx = role - Qt::UserRole - 1;
//        QModelIndex modelIndex = this->index(index.row(), columnIdx);
//        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
//    }
//    return value;
//}

//void CardsSQLModel::refresh()
//{
//    this->setQuery(SQL_SELECT);
//}


