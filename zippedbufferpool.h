#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H
#include <QPair>
#include <zippedbuffer.h>

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair<int, int> tryGet();
    void done();
};

#endif // ZIPPEDBUFFERPOOL_H
