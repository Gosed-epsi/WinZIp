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
#include <QProgressBar>

/**
 * @file mainwindow.cpp
 * IHM de l'application.
 *
 * @author Edgar
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    epsiFileCompressor_ = new EpsiFileCompressor(); //!<

    auto window = new QWidget(this); //!< fenetre
    onglets_ = new QTabWidget(window); //!< bar d'onglet de la fenetre
    onglets_->setGeometry(30, 20, 250, 220); //!< localisation et taille des onglets dans la fenetre

    auto windowCompress = new QWidget; //!< onglet pour la compression
    auto windowUncompress = new QWidget; //!< onglet pour la décompression

    nameFile_ = new QLineEdit("",window); //!< champ pour définir le nom du fichier compressé
    directorySelector_ = new DirectorySelector(window); //!< bouton de séléction du répertoire
    buttonCompress_ = new QPushButton("Compresser", window); //!< bouton pour lancer la compression
    progressCompress_ = new QProgressBar();  //!< bar de progression de la compression
    progressCompress_->setValue(0);  //!< initialisation de la bar de progression


    fileSelector_ = new FileSelector(window); //!< bouton de séléction du fichier
    //unixButton_ = new QRadioButton(window); //!< bouton pour les systèmes Unix
    //unixButton_->setText("Unix");
    //windowsButton_ = new QRadioButton(window); //!< bouton pour les systèmes Windows
    //windowsButton_->setText("Windows");
    buttonUncompress_ = new QPushButton("Décompresser", window); //!< bouton pour lancer la décompression
    progressUncompress_ = new QProgressBar(); //!< bar de progression de la décompression
    progressUncompress_->setValue(0); //!< initialisation de la bar de progression

    auto layoutCompress = new QVBoxLayout; //!< layout de la compression
    auto layoutUncompress = new QVBoxLayout; //!< layout de la décompression

    layoutCompress->addWidget(new QLabel("Nom de l'archive :", window)); //!<
    layoutCompress->addWidget(nameFile_);                                //!<
    layoutCompress->addWidget(new QLabel("Répertoire :", window));       //!< Ajout des éléments dans le layout de compression
    layoutCompress->addWidget(directorySelector_);                       //!<
    layoutCompress->addWidget(buttonCompress_);                          //!<

    layoutUncompress->addWidget(fileSelector_);                          //!<
    //layoutUncompress->addWidget(unixButton_);                          //!<
    layoutCompress->addWidget(progressCompress_);                        //!< Ajout des éléments dans le layout de décompression
    //layoutUncompress->addWidget(windowsButton_);                       //!<
    layoutUncompress->addWidget(buttonUncompress_);                      //!<
    layoutUncompress->addWidget(progressUncompress_);                    //!<

    QObject::connect(buttonCompress_,SIGNAL(released()),this, SLOT(compress())); //!< connexion du bouton de compression avec la fonction
    connect(directorySelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir))); //!< connexion du bouton de séléction du répertoire avec la fonction

    QObject::connect(buttonUncompress_,SIGNAL(released()),this, SLOT(uncompress())); //!< connexion du bouton de décompression avec la fonction
    connect(fileSelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir))); //!< connexion du bouton de séléction du fichier avec la fonction

    windowCompress->setLayout(layoutCompress); //!< ajout du layout de compression dans l'onglet de compression
    windowUncompress->setLayout(layoutUncompress); //!< ajout du layout de compression dans l'onglet de décompression

    onglets_->addTab(windowCompress, "Compression"); //!< ajout de l'onglet de compression dans la bar d'onglet
    onglets_->addTab(windowUncompress, "Décompression"); //!< ajout de l'onglet de décompression dans la bar d'onglet

    setGeometry(300,200,300,260); //!< taille et position de la fenetre
    setCentralWidget(window); //!< centré les éléments au sein de la fenetre
    show(); //!< affichage de la fenetre

}

MainWindow::~MainWindow()
{
}

void MainWindow::compress() {

    QString folder(directorySelector_->currentFolder().absolutePath()); //!< récupération du chemin du répertoire
    QString name(nameFile_->text()); //!< récupération du nom de la future archive

    epsiFileCompressor_->compress(folder,name); //!< execution de la compression

    progressCompress_->setValue(100); //!< remplissage de la bar de progression
}

void MainWindow::uncompress() {

    //QString slash;
    //if (unixButton_->isChecked()) slash = "/";
    //if (windowsButton_->isChecked()) slash = "\\";

    QString folder(fileSelector_->currentFolder().absolutePath()); //!< récupération du chemin du fichier
    QString file(fileSelector_->currentFile()); //!< récupération du nom du fichier

    epsiFileCompressor_->uncompress(file,folder); //!< execution de la décompression

    progressUncompress_->setValue(100); //!< remplissage de la bar de progression
}

void MainWindow::directoryChanged(const QDir &/*dir*/) {

}


