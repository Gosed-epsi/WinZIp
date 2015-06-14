#include "epsifilecompressor.h"
#include "filepool.h"
#include "zippedbufferpool.h"
#include "writer.h"
#include "zipper.h"
#include <QFile>
#include <QStringList>

EpsiFileCompressor::EpsiFileCompressor(){}

void EpsiFileCompressor::uncompress(QString &ecfFileName, QString &folder )
{
    QFile fileUncompressed(ecfFileName);
    fileUncompressed.open(QIODevice::ReadOnly);
    QDataStream dataStreamUncompress(&fileUncompressed);
    ZippedBufferPool* zippedBufferPool = new ZippedBufferPool();
    while (dataStreamUncompress.atEnd() == false)
    {
        ZippedBuffer* zippedBuffer = new ZippedBuffer();
        zippedBuffer->read(dataStreamUncompress);
        zippedBufferPool->put(zippedBuffer);
    }
    Writer* write = new Writer(folder, ecfFileName, *zippedBufferPool);
    write->writeUnCompressedFiles();
    fileUncompressed.close();
}

void EpsiFileCompressor::compress(QString &folder, QString &ecfFileName)
{
    QStringList *filePool = new FilePool(folder);
    ZippedBufferPool *zippedBufferPool = new ZippedBufferPool();
    for(QStringList::iterator it = filePool->begin(); it != filePool->end(); it++)
    {
        Zipper *zipper = new Zipper(zippedBufferPool, folder);
        zipper->CompressFile(*it);
    }
    Writer *writer = new Writer(folder, ecfFileName, *zippedBufferPool);
    writer->writeCompressedFile();
}
