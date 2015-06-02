#include "filepool.h"


FilePool::FilePool(const QString &folder)
{
    folder_ = folder;
    fillFileList(folder_);
}

void FilePool::fillFileList(const QString &folder){

    QDir directory(folder);

    foreach (QFileInfo entry, directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {

        if(entry.isDir()){
            fillFileList(entry.absoluteFilePath());
        }
        else if(entry.isFile() == true){

            files_.push_back(entry.absoluteFilePath());
        }
    }
}
