#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H
#include <QString>

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    void compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
};

#endif // EPSIFILECOMPRESSOR_H
