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
        //TextStream permet de lire le fichier (à changer par un récupérateur de bytes)
        QTextStream in(&file);
        //Lit toutes les lignes
        QString f=in.readAll();
        //iosstream affichage du contenu
        std::cout << pathFile.toStdString() << f.toStdString() << std::endl;
        //fermeture du fichier
        file.close();
    }
}


void run_dezipper(const QString &fileDezip){

}

int main(int argc, char *argv[])
{
    run_zipper("/Users/sinys/EPSI/IA/Clip");
}

