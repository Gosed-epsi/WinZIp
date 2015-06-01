#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

class ZippedBuffer
{
public:
    ZippedBuffer();
    QString &nameFolder;
    QByteArray &byteCompress;
    void write(QDataStream &stream);
    void read(QDataStream &stream);
};

#endif // ZIPPEDBUFFER_H
