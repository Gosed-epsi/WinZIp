#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

#include <QString>


class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    void uncompress(const QString &ecfFileName, const QString &folder );
    void compress(const QString &folder, const QString &ecfFileName);
};

#endif // EPSIFILECOMPRESSOR_H
