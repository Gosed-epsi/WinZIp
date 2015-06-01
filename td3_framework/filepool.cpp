#include "filepool.h"
#include <QDir>
#include <QMutexLocker>

FilePool::FilePool(const QString &folder, const QString &suffix)
{
    suffix_ = suffix;
    findFileInFolderAndSubfolders(folder);
}
void FilePool::findFileInFolderAndSubfolders(const QString &folder)
{
    QDir dir(folder);

    foreach (const QFileInfo &entry,
             dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
        if( entry.isDir() == true )
        {
            findFileInFolderAndSubfolders(entry.filePath());
        }
        else if(entry.isFile() == true
                && entry.suffix() == suffix_) {

            append(entry.absoluteFilePath());
        }
    }
}
