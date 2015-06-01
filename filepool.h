#ifndef FILEPOOL_H
#define FILEPOOL_H
#include <QDir>
#include <QList>
#include <QMutex>

class FilePool
{
public:
    FilePool(const QString &folder);
    QString tryGetFile();

private :
    void fillFileList(const QString &folder);
    QString folder_;
    QList<QString> files_;
    QMutex mutex_;
};

#endif // FILEPOOL_H
