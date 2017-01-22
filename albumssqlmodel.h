#ifndef ALBUMSSQLMODEL_H
#define ALBUMSSQLMODEL_H
#include <QSqlQueryModel>

class AlbumsSQLModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum Roles {
        AlbumIDRole = Qt::UserRole + 1, AlbumNameRole, CardsInAlbumRole, AlbumAddedRole, AlbumEditedRole};

    explicit AlbumsSQLModel(QObject *parent = 0);

    void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    void setQuery(const QSqlQuery &query);

    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}

private:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;
};

#endif // ALBUMSSQLMODEL_H
