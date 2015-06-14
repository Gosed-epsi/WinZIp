#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QPair>


ZippedBufferPool::ZippedBufferPool(){}

void ZippedBufferPool::put(ZippedBuffer *zb)
{
    _listZippedBuffer.insert(_listZippedBuffer.begin(),zb);
}

QPair<bool,ZippedBuffer> ZippedBufferPool::tryGet()
{
    bool value = false;
    ZippedBuffer zippedBuffer;
    QPair<bool,ZippedBuffer> pair = qMakePair(value,zippedBuffer);
    return pair;
}
void ZippedBufferPool::done()
{
    tryGet();
}

