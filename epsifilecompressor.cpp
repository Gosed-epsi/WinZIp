#include "epsifilecompressor.h"
#include "filepool.h"
#include "zippedbufferpool.h"
#include "writer.h"
#include "zipper.h"
#include <QFile>

#include "qstringlist.h"

EpsiFileCompressor::EpsiFileCompressor()
{
}

void EpsiFileCompressor::uncompress(QString &ecfFileName, QString &folder )
{
    //QString pathCompressFile = folder + "/" + ecfFileName + ".ecf";
    ZippedBufferPool zippedBufferPool;
    Writer *write = new Writer(folder, ecfFileName, zippedBufferPool);
    write->writeUnCompressedFiles();

}

void EpsiFileCompressor::compress(QString &folder, QString &ecfFileName)
{
    QStringList *filePool = new FilePool(folder);
    ZippedBufferPool *zippedBufferPool = new ZippedBufferPool();

    for(QStringList::iterator it = filePool->begin(); it != filePool->end(); it++)
    {
        Zipper *zipper = new Zipper(zippedBufferPool);
        zipper->CompressFile(*it);

    }

    Writer *writer = new Writer(folder, ecfFileName, *zippedBufferPool);
    writer->writeCompressedFile();
}
