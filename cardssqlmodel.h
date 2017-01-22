#ifndef CARDSSQLMODEL_H
#define CARDSSQLMODEL_H
#include <QSqlQueryModel>

class CardsSQLModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum Roles {
        CardMIDRole = Qt::UserRole + 1, CardAlbumMIDRole, CardIDRole, CardNameRole, CardImageURLRole, CardSubtypeRole, CardSupertypeRole, CardNumberRole, CardArtistRole, CardRarityRole, CardSeriesRole, CardSetNameRole, CardSetCodeRole, CardStatusRole, CardConditionRole, CardAddedRole, CardEditedRole};
    explicit CardsSQLModel(QObject *parent = 0);


    void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    void setQuery(const QSqlQuery &query);

    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}
//    void refresh();

signals:

//public slots:
//    void cardAdded(QString imageURL);
//    void cardRemoved(QString imageURL);
//    void cardUpdated(QString imageURL);
private:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;
};

#endif // CARDSSQLMODEL_H
