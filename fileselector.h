#ifndef FILESELECTOR_H
#define FILESELECTOR_H


#include <QWidget>
#include <QDir>
class QLineEdit;
class FileSelector : public QWidget
{
    Q_OBJECT
public:
    explicit FileSelector(QWidget *parent = 0);
    const QDir &currentFolder()const;
    const QString &currentFile()const;
signals:
    void directoryChanged( const QDir &directory );
public slots:
    void validateFolder();


private slots:
    void selectFolder();

private:
    QLineEdit *path_;
    QDir currentFolder_;
    QString currentFile_;
};

#endif // DIRECTORYSELECTOR_H
