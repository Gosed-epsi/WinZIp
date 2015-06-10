#include "mainwindow.h"
#include "directoryselector.h"
#include "fileselector.h"


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
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    epsiFileCompressor_ = new EpsiFileCompressor();

    auto window = new QWidget(this);
    onglets_ = new QTabWidget(window);
    onglets_->setGeometry(30, 20, 250, 220);

    auto windowCompress = new QWidget;
    auto windowUncompress = new QWidget;

    nameFile_ = new QLineEdit("",window);
    directorySelector_ = new DirectorySelector(window);
    buttonCompress_ = new QPushButton("Compresser", window);


    fileSelector_ = new FileSelector(window);
    unixButton_ = new QRadioButton(window);
    unixButton_->setText("Unix");
    windowsButton_ = new QRadioButton(window);
    windowsButton_->setText("Windows");
    buttonUncompress_ = new QPushButton("Décompresser", window);

    auto layoutCompress = new QVBoxLayout;
    auto layoutUncompress = new QVBoxLayout;

    layoutCompress->addWidget(new QLabel("Nom de l'archive :", window));
    layoutCompress->addWidget(nameFile_);
    layoutCompress->addWidget(new QLabel("Répertoire :", window));
    layoutCompress->addWidget(directorySelector_);
    layoutCompress->addWidget(buttonCompress_);

    layoutUncompress->addWidget(fileSelector_);
    layoutUncompress->addWidget(unixButton_);
    layoutUncompress->addWidget(windowsButton_);
    layoutUncompress->addWidget(buttonUncompress_);

    QObject::connect(buttonCompress_,SIGNAL(released()),this, SLOT(compress()));
    connect(directorySelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir)));

    QObject::connect(buttonUncompress_,SIGNAL(released()),this, SLOT(uncompress()));
    connect(fileSelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir)));

    windowCompress->setLayout(layoutCompress);
    windowUncompress->setLayout(layoutUncompress);

    onglets_->addTab(windowCompress, "Compression");
    onglets_->addTab(windowUncompress, "Décompression");

    setGeometry(300,200,300,260);
    setCentralWidget(window);
    show();

}

MainWindow::~MainWindow()
{
}

void MainWindow::compress() {

    QString folder(directorySelector_->currentFolder().absolutePath());
    QString name(nameFile_->text());

    epsiFileCompressor_->compress(folder,name);
}

void MainWindow::uncompress() {

    QString slash;
    if (unixButton_->isChecked()) slash = "/";
    if (windowsButton_->isChecked()) slash = "\\";

}

void MainWindow::directoryChanged(const QDir &/*dir*/) {

}


