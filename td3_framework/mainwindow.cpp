#include "mainwindow.h"
#include "directoryselector.h"


#include <QVBoxLayout>
#include <QPushButton>
#include <QtConcurrentFilter>
#include <QtConcurrentMap>
#include <QFutureWatcher>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    auto window = new QWidget(this);
    directorySelector_ = new DirectorySelector(window);
    auto button = new QPushButton("Search", window);
    toSearch_ = new QLineEdit("double",window);
    fileSuffix_ = new QLineEdit("c", window);
    result_ = new QTextEdit(window);

    auto layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Search string:", window));
    layout->addWidget(toSearch_);

    layout->addWidget(new QLabel("In folder:", window));
    layout->addWidget(directorySelector_);
    layout->addWidget(new QLabel("For files:", window));
    layout->addWidget( fileSuffix_ );
    layout->addWidget(result_);
    layout->addWidget(button);

    connect(button,SIGNAL(clicked()),this, SLOT(process()));
    connect(directorySelector_,SIGNAL(directoryChanged(QDir)),this,SLOT(directoryChanged(QDir)));

    window->setLayout(layout);
    setCentralWidget(window);
    show();

}

MainWindow::~MainWindow()
{
}

void MainWindow::process() {
  QString folder(directorySelector_->currentFolder().absolutePath());

  QString suffix(fileSuffix_->text());
  QString search(toSearch_->text());
  result_->clear();
  FilePool pool(folder, suffix);
  for(const auto &file: pool){
      result += file + "\n";
  }
  result_->setText(result);

}

void MainWindow::directoryChanged(const QDir &/*dir*/) {

}


