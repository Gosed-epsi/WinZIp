#ifndef FILEPOOL_H
#define FILEPOOL_H
#include <QString>
#include <QStringList>
#include <iostream>
#include <QList>

class FilePool : public QStringList
{
public:
    FilePool(){}
    FilePool(const QString &folder);

private:

    void findFileInFolderAndSubfolders(const QString &folder);
};

#endif // FILEPOOL_H
