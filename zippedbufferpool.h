#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(ZippedBuffer &zb);
    QPair tryGet();
    void done();
};

#endif // ZIPPEDBUFFERPOOL_H
