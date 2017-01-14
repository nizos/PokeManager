#include "albums.h"

// Constructors & Destructor
Albums::Albums()
{
    this->albumsManager = nullptr;
}

Albums::Albums(AlbumsManager *albumsManager)
{

    this->albumsManager = albumsManager;
}

Albums::~Albums()
{
    this->albumsManager = nullptr;
}

int Albums::linearSearch(const int albumId) const
{
    int pos = -1;
    for (int i = 0; i < this->albumIds.count() && pos == -1; i++)
    {

        if (this->albumIds.at(i) == QString::number(albumId))
        {
            pos = i;
        }
    }
    return pos;
}

// Album Getters
int Albums::getNrOfAlbums() const
{
    return this->albumIds.count();
}

int Albums::getAlbumId(int pos) const
{
    return this->albumIds.at(pos).toInt();
}

QStringList Albums::getAlbumIds() const
{
    return this->albumIds;
}


// Management
void Albums::addAlbum(const int albumId)
{
    this->albumIds << QString::number(albumId);
}

void Albums::removeAlbum(const int albumId)
{
    int pos = this->linearSearch(albumId);
    if (pos == -1)
    {
        QString exc = "albumId not found.";
        throw exc;
    }
    this->albumIds.removeAt(pos);
}
