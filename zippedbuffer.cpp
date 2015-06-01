#include "zippedbuffer.h"
#include <QString>
#include <QByteArray>
#include <QDataStream>

ZippedBuffer::ZippedBuffer()
{
    this->nameFolder = nameFolder;
    this->byteCompress = byteCompress;
}

void ZippedBuffer::write(QDataStream &stream)
{

}

void ZippedBuffer::read(QDataStream &stream)
{

}
