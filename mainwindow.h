#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFuture>
class QTextEdit;
class QLineEdit;
class QDir;
class QProgressBar;
class DirectorySelector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void process();
    void directoryChanged(const QDir &dir);

private:
    DirectorySelector *directorySelector_;
    QTextEdit *result_;
    QLineEdit *toSearch_;
    QLineEdit *fileSuffix_;

};

#endif // MAINWINDOW_H
