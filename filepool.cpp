#include "filepool.h"
#include <QDir>

FilePool::FilePool(const QString &folder)
{
    findFileInFolderAndSubfolders(folder);
}

void FilePool::findFileInFolderAndSubfolders(const QString &folder)
{
    QDir dir(folder);
    foreach (const QFileInfo &entry, dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot))
    {
        if(entry.isDir() == true)
        {
            findFileInFolderAndSubfolders(entry.filePath());
        }
        else if (entry.isFile() == true)
        {
            append(entry.absoluteFilePath());
        }
    }
}

