#include "zippedbuffer.h"
#include <QDataStream>
#include <iostream>

ZippedBuffer::ZippedBuffer(){}

void ZippedBuffer::write(QDataStream &stream)
{
   stream << _name;
   stream << qCompress(_compressedFile);
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> _name >> _compressedFile ;
}

