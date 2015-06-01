#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H
#include <QString>
#include <QByteArray>

class ZippedBuffer
{
    private:
        QString nameFolder;
        QByteArray byteCompress;
    public:
        ZippedBuffer();
        void write(QDataStream &stream);
        void read(QDataStream &stream);
};

#endif // ZIPPEDBUFFER_H
