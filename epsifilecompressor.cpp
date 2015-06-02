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

void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder )
{
    //QString pathCompressFile = folder + "/" + ecfFileName + ".ecf";
    ZippedBufferPool zippedBufferPool;
    Writer *write = new Writer(folder, ecfFileName, zippedBufferPool);
    write->writeUnCompressedFiles();

}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
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
