#ifndef ZIPPER_H
#define ZIPPER_H
#include "zippedbuffer.h"
#include "zippedbufferpool.h"
#include <QString>

class Zipper
{
public:
    Zipper(ZippedBufferPool* ZBP,QString rootDirectory);
    void CompressFile(QString file);
    ZippedBufferPool* _ZBP;
    QString _RootDirectory;
};

#endif // ZIPPER_H
