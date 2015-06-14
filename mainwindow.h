#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFuture>
#include <QTabWidget>
#include <QPushButton>
#include <QLineEdit>
#include <epsifilecompressor.h>

class QTextEdit;
class QLineEdit;
class QDir;
class QProgressBar;
class DirectorySelector;
class FileSelector;
class QRadioButton;
class QProgressBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void uncompress();
    void compress();
    void directoryChanged(const QDir &dir);

private:
    QTabWidget *onglets_;
    DirectorySelector *directorySelector_;
    FileSelector *fileSelector_;
    QTextEdit *result_;
    QLineEdit *toSearch_;
    QLineEdit *fileSuffix_;
    QRadioButton *unixButton_;
    QRadioButton *windowsButton_;
    QPushButton *buttonCompress_;
    QPushButton *buttonUncompress_;
    QProgressBar *progressCompress_;
    QProgressBar *progressUncompress_;
    QLineEdit *nameFile_;

    EpsiFileCompressor *epsiFileCompressor_;

};

#endif // MAINWINDOW_H
