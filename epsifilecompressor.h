#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    void compress(const QString &folder, const QString &ecfFileName);
    uncompress(const QString &ecfFileName, const QString &folder);
};

#endif // EPSIFILECOMPRESSOR_H
