#include "writer.h"
#include "zippedbuffer.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QList>
#include <QDataStream>



Writer::Writer(QString directory, QString ecfFileName, ZippedBufferPool pool)
{
    _poolZippedBuffer = pool;
    QStringList resultat = directory.split("/");

    for(int i =0; i<resultat.size()-1; i++)
    {
        _parentDirectory += resultat[i] + "/";
    }
    _ecfFileName = ecfFileName;
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
    QFile compressFile(_ecfFileName);

    if(compressFile.exists() == true)
    {
        compressFile.open(QIODevice::ReadWrite);

        ZippedBuffer *ZB = new ZippedBuffer();
        ZB->_name = "compress";

        ZB->_compressedFile = compressFile.readAll();
        QDataStream compressStream(&compressFile);
        ZB->read(compressStream);
    }
    else
    {
        std::cout << "Le fichier choisi n'hexiste pas." << std::endl;
    }
}
