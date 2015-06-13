#include "writer.h"
#include "zippedbuffer.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QList>
#include <QDataStream>
#include <QDir>



Writer::Writer(QString directory, QString ecfFileName, ZippedBufferPool pool)
{
    _poolZippedBuffer = pool;
    QStringList resultat = directory.split("/");

    for(int i =0; i<resultat.size()-1; i++)
    {
        _parentDirectory += resultat[i] + "/";
    }
    _ecfFileName = ecfFileName;
    _rootDirectory = directory;
}

void Writer::writeCompressedFile()
{
    QString chemin = _parentDirectory + _ecfFileName + ".ecf";
    QFile file(chemin);
    file.open(QIODevice::Append);

    std::cout << chemin.toStdString() << std::endl;
    QDataStream data(&file);

    std::list<ZippedBuffer*> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;
    for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        ZippedBuffer *zippedBuffer = ((ZippedBuffer*) *it);
        data << zippedBuffer->_name;
        data << qCompress(zippedBuffer->_compressedFile);
    }

    file.close();
}

void Writer::writeUnCompressedFiles()
{
    //Supression de l'extention
    _ecfFileName.remove(_ecfFileName.size() - 4, _ecfFileName.size());

    QString chemin = _rootDirectory;
    //std::cout << _rootDirectory.toStdString() << std::endl;


        std::list<ZippedBuffer*> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;

        int count = 0;

        for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
        {
            ZippedBuffer *zippedBuffer = ((ZippedBuffer*) *it);

            int cptFileNameSplit  =zippedBuffer->_name.split("/").size();

            if(cptFileNameSplit > 1)
            {

                QString directoryParent = zippedBuffer->_name;
                QString stringPath = directoryParent;
                QString directoryToCreate ="";
                for(int i = 0;i<cptFileNameSplit-1;i++)
                {
                    directoryToCreate += stringPath.split("/")[i];
                    directoryParent = createDirectory(chemin,directoryToCreate);
                    directoryToCreate += "/";
                }
            }
            QString cheminFile = chemin + "/" + zippedBuffer->_name;
            QFile file(cheminFile);
            file.open(QFile::WriteOnly);

            QDataStream data(&file);

            QByteArray uncompressedArray(qUncompress(zippedBuffer->_compressedFile));
            data.writeRawData(uncompressedArray.constData(), uncompressedArray.size());

            file.close();

            //std::cout << "uncompress : " << zippedBuffer->_name.toStdString() << std::endl;
            count += 1 ;

        }

        std::cout << "NB fichiers décompressés : " << count << std::endl;
}

QString Writer::createDirectory(QString directoryParent,QString directoryToCreate)
{
    QString directoryPath = directoryParent+"/"+directoryToCreate;
    std::cout << "Directory to create : " << directoryPath.toStdString() << std::endl;
    QDir dir = QDir::root();
    dir.mkdir(directoryPath);
    return directoryPath;
}
