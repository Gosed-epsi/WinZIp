#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <list>
#include <filepool.h>
#include <QTextStream>

void run_zipper(const QString &fileZip)
{
    FilePool filePool(fileZip);

    //Parcours de la liste des fichiers recuperer
    for (QString pathFile : filePool.files_)
    {
        //Création d'un file
        QFile file(pathFile);
        //Definition de l'ouverture (obligatoire sinon pas d'accès)
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        //Recuperation des bytes
        QByteArray bytesFile = file.readAll();
        //Bytes compresser
        QByteArray bytesCompress = qCompress(bytesFile);
        //fichier de bytes
        QFile fileCompress("/Users/sinys/EPSI/IA/Clip/test.zip");
        //Ouverture
        fileCompress.open(QIODevice::WriteOnly | QIODevice::Text);
        //Ecriture
        fileCompress.write(bytesCompress);
        //fermeture du fichier
        file.close();
        fileCompress.close();
        break;
    }
}


void run_dezipper(const QString &fileDezip){

    //fichier de bytes
    QFile fileCompress("/Users/sinys/EPSI/IA/Clip/test.zip");
    //Ouverture
    fileCompress.open(QIODevice::ReadOnly | QIODevice::Text);
    //Recuperation des bytes
    QByteArray bytesFile = fileCompress.readAll();
    //Bytes decompresser
    QByteArray bytesCompress = qUncompress(bytesFile);
    //Création d'un file
    QFile file("/Users/sinys/EPSI/IA/Clip/clp.clp");
    //Definition de l'ouverture (obligatoire sinon pas d'accès)
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    //Ecriture
    file.write(bytesCompress);
    //fermeture du fichier
    file.close();
    fileCompress.close();
}

int main(int argc, char *argv[])
{
    run_zipper("/Users/sinys/EPSI/IA/Clip");
}

