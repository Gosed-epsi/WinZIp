#include "filepool.h"
#include <QDir>
#include <QList>
#include <QMutex>

FilePool::FilePool(const QString &folder)
{
    folder_ = folder;
    fillFileList(folder_);
}

QString FilePool::tryGetFile(){

    QString result;
    QMutexLocker locker(&mutex_);
    //mutex.lock();
    if (files_.empty() == false){
        result = files_.front();
        files_.pop_front();
    }
    //mutex.unlock();
    return result;
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
