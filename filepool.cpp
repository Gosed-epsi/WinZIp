#include "filepool.h"


FilePool::FilePool(const QString &folder)
{
    folder_ = folder;
    fillFileList(folder_);
}

/*
QString FilePool::tryGetFile(){

    QString result;
    QMutexLocker locker(&mutex_);

    for (QString theFile : files_) {
        std::cout << theFile.toStdString() << std::endl;
    }

    if (files_.empty() == false){
        result = files_.front();
        files_.pop_front();
    }
    return result;
}*/

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
