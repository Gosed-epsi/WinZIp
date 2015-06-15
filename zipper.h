#ifndef ZIPPER_H
#define ZIPPER_H
#include "zippedbuffer.h"
#include "zippedbufferpool.h"
#include <QString>
#include <QThread>

class Zipper : public QThread
{
public:
    Zipper(ZippedBufferPool* ZBP,QString rootDirectory);
    void CompressFile(QString file);
    ZippedBufferPool* _ZBP;
    QString _RootDirectory;
};

#endif // ZIPPER_H
