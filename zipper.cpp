#include "zipper.h"
#include "zippedbuffer.h"
#include "zippedbufferpool.h"
#include "filepool.h"
#include <QDataStream>
#include <QFile>

using namespace std;

Zipper::Zipper(ZippedBufferPool* ZBP,QString rootDirectory)
{
    _ZBP = ZBP;
    _RootDirectory = rootDirectory;
}


void Zipper::CompressFile(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QByteArray bytesArray = file.readAll();
    file.close();
    int rootSplitSize = _RootDirectory.split("/").size();
    int fileSplitSize = filePath.split("/").size();
    QStringList resultat = filePath.split("/");
    QString fileName = "";
    ZippedBuffer* zipBuffer = new ZippedBuffer();
    if((fileSplitSize - rootSplitSize)>1){
        for(int i= rootSplitSize;i<fileSplitSize;i++)
        {
            if(i < fileSplitSize-1)
                fileName += resultat[i] +"/";
            else
                fileName += resultat[i];
        }
    }
    else
    {
        fileName = resultat[resultat.size()-1];
    }
    zipBuffer->_name = fileName;
    zipBuffer->_compressedFile = qCompress(bytesArray);
    _ZBP->put(zipBuffer);
}
