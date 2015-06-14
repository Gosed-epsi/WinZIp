#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H
#include "zippedbuffer.h"
#include <QPair>

class ZippedBufferPool
{
public:

    ZippedBufferPool();
    void put(ZippedBuffer *zb);
    QPair<bool,ZippedBuffer> tryGet();
    void done();

    std::list<ZippedBuffer*> _listZippedBuffer;
};

#endif // ZIPPEDBUFFERPOOL_H
