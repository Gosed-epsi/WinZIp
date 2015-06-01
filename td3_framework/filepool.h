#ifndef FILEPOOL_H
#define FILEPOOL_H
#include <QString>
#include <QStringList>
#include <QMutex>
/**
 * @brief La class FilePool représente un ensemble de
 * fichier à traiter.
 */
class FilePool : public QString
{
public:

    FilePool(const QString &folder, const QString &suffix);

private:

    void findFileInFolderAndSubfolders(const QString &folder);

    QString suffix_;
};

#endif // FILEPOOL_H
