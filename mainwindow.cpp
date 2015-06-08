#include "mainwindow.h"
#include "directoryselector.h"


#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QtConcurrentFilter>
#include <QtConcurrentMap>
#include <QFutureWatcher>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QProgressDialog>
#include <QObject>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    epsiFileCompressor = new EpsiFileCompressor();

    auto window = new QWidget(this);
    directorySelector_ = new DirectorySelector(window);
    unixButton_ = new QRadioButton(window);
    windowsButton_ = new QRadioButton(window);
    buttonCompress = new QPushButton("Compresser", window);
    buttonUncompress = new QPushButton("Décompresser", window);
    nameFile = new QLineEdit("",window);

    auto layout = new QVBoxLayout;

    layout->addWidget(nameFile);
    layout->addWidget(new QLabel("In folder:", window));
    layout->addWidget(directorySelector_);
    layout->addWidget(new QLabel("Unix:", window));
    layout->addWidget(unixButton_);
    layout->addWidget(new QLabel("Windows:", window));
    layout->addWidget(windowsButton_);
    layout->addWidget(buttonCompress);
    layout->addWidget(buttonUncompress);

    QObject::connect(buttonCompress,SIGNAL(released()),this, SLOT(compress()));
    connect(directorySelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir)));

    window->setLayout(layout);
    setCentralWidget(window);
    show();

}

MainWindow::~MainWindow()
{
}

void MainWindow::compress() {

    QString folder(directorySelector_->currentFolder().absolutePath());
    QString name(nameFile->text());

    epsiFileCompressor->compress(folder,name);
}

void MainWindow::uncompress() {
    QString folder(directorySelector_->currentFolder().absolutePath());

    QString suffix(fileSuffix_->text());
    QString search(toSearch_->text());
    result_->clear();

    QString slash;
    if (unixButton_->isChecked()) slash = "/";
    if (windowsButton_->isChecked()) slash = "\\";

}

void MainWindow::directoryChanged(const QDir &/*dir*/) {

}


