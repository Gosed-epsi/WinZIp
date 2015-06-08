#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

#include <QString>


class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    void uncompress(QString &ecfFileName, QString &folder );
    void compress(QString &folder, QString &ecfFileName);
};

#endif // EPSIFILECOMPRESSOR_H
