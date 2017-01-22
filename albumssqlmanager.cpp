#include "albumssqlmanager.h"


AlbumsSQLManager::AlbumsSQLManager(QObject* parent) : QObject(parent)
{

}


void AlbumsSQLManager::setDB(QSqlDatabase* db)
{
    this->db = db;
}

void AlbumsSQLManager::setCardsSQLManager(CardsSQLManager* cardsSQLManager)
{
    this->cardsSQLManager = cardsSQLManager;
}

void AlbumsSQLManager::addAlbum(QString albReq)
{
    int albID;
    QString insertAlbumCommand = "INSERT INTO [dbo].[Albums2]([albumName],[albumAdded],[albumEdited]) VALUES(:albumName,:albumAdded,:albumEdited)";

    QSqlQuery qryAlbum;
    qryAlbum.prepare(insertAlbumCommand);
    qryAlbum.bindValue(":albumName",albReq);
    qryAlbum.bindValue(":albumAdded",QDateTime::currentDateTime());
    qryAlbum.bindValue(":albumEdited",QDateTime::currentDateTime());
    if(qryAlbum.exec())
    {
        albID = qryAlbum.lastInsertId().toInt();
        qDebug() << "Album " << albID << " Added";
        emit albumAdded(albID);
    }
    else
    {
        qDebug() << "ERROR: Could not add Album: " << albReq << db->lastError();
    }
}


void AlbumsSQLManager::removeAlbum(int albID)
{
    QString deleteAlbumCommand = "DELETE FROM Albums2 WHERE ID =:albID";
    QSqlQuery qryAlbum;
    qryAlbum.prepare(deleteAlbumCommand);
    qryAlbum.bindValue(":albID",albID);
    if(qryAlbum.exec())
    {
        // Album deleted
        qDebug() << "Album " << albID << " Removed.";
        emit albumRemoved(albID);

        // If Album removed, remove cards
        int crdID;
        QString selectAlbumCardsCommand = "SELECT FROM Cards3 WHERE albumMID =:albID";
        QSqlQuery qrySelectCards;
        qrySelectCards.prepare(selectAlbumCardsCommand);
        qrySelectCards.bindValue(":albID",albID);
        while(qrySelectCards.next())
        {
            // Found Card in Album
            crdID = qrySelectCards.value(0).toInt();
            qDebug() << "Card Found. Card: " << crdID << " in Album: " << albID << ".";

            // Delete Card
            QString deleteAlbumCardsCommand = "DELETE FROM Cards3 WHERE ID =:crdID";
            QSqlQuery qryCards;
            qryCards.prepare(deleteAlbumCardsCommand);
            qryCards.bindValue(":crdID",crdID);
            if(qryCards.exec())
            {
                // Card deleted
                qDebug() << "Card " << crdID << "Removed.";
                emit cardRemoved(albID, crdID);
            }
            else
            {
                // Coudln't delete Card
                qDebug() << "ERROR: Could not remove Card: " << crdID << " from Album: " << albID << ".";
                qDebug() << db->lastError();
            }
        }
        if(!qrySelectCards.exec())
        {
            // Couldn't delete Cards
            qDebug() << "ERROR: Could not delete Cards in Album: " << albID << ".";
            qDebug() << db->lastError();
        }
    }
    else
    {
        // Couldn't delete Album
        qDebug() << "ERROR: Could not delete Album: " << albID << ".";
        qDebug() << db->lastError();
    }
}

void AlbumsSQLManager::addCard(int albID, QString crdReq)
{
    this->cardsSQLManager->addCard(albID,crdReq);
}

void AlbumsSQLManager::removeCard(int albID, int crdID)
{
    this->cardsSQLManager->removeCard(albID,crdID);
}


int AlbumsSQLManager::getNrOfCards(int albID)
{
    int nrOfCards = 0;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Cards3 WHERE albumMID=:albID");
    qry.bindValue(":albID",albID);
    if(qry.exec())
    {
        while(qry.next())
        {
            nrOfCards++;
        }
    }
    else
    {
        qDebug() << "Error: Couldn't get nr. of Cards in Album " << albID << ".";
        qDebug() << db->lastError();
    }
//    if(nrOfCards == -1)
//    {
//        QString exc = "Error: Couldn't get nr. of Cards.";
//        throw exc;
//    }
    qDebug() << "Cards in Album: " << albID << " = " << nrOfCards;
    return nrOfCards;
}

int AlbumsSQLManager::getNrOfAlbums()
{
    int nrOfAlbums = 0;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Albums2");
    if(qry.exec())
    {
        while(qry.next())
        {
            nrOfAlbums++;
        }
    }
    else
    {
        qDebug() << "Error: Couldn't get nr. of Albums.";
        qDebug() << db->lastError();
    }
//    if(nrOfAlbums == -1)
//    {
//        QString exc = "Error: Couldn't get nr. of Albums.";
//        throw exc;
//    }
    qDebug() << "Nr of Albums = " << nrOfAlbums;
    return nrOfAlbums;
}
