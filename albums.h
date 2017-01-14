#ifndef ALBUMS_H
#define ALBUMS_H
#include <QDebug>
#include <QString>
#include <QList>

class AlbumsManager;
class Albums
{
private:
    // Private variables
    QStringList albumIds;

    int linearSearch(const int albumId) const;
    AlbumsManager* albumsManager;

public:
    // Constructors & Destructor
    Albums();
    Albums(AlbumsManager *albumsManager);
    ~Albums();

    // Album Getters
    int getNrOfAlbums() const;
    int getAlbumId(int pos) const;
    QStringList getAlbumIds() const;

    // Management
    void addAlbum(const int albumId);
    void removeAlbum(const int albumId);
};

#endif // ALBUMS_H
