#include "FileSelector.h"
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

FileSelector::FileSelector(QWidget *parent) :
    QWidget(parent),currentFolder_("c:\\")
{
    auto button = new QPushButton("...", this);
    path_ = new QLineEdit(currentFolder().absolutePath(), this);
    path_->setEnabled(false);
    auto layout = new QHBoxLayout;
    layout->addWidget(path_);
    layout->addWidget(button);

    connect(button, SIGNAL(clicked()),this, SLOT(selectFolder()));
    connect(path_,SIGNAL(editingFinished()),this, SLOT(validateFolder()));

    setLayout(layout);
}
void FileSelector::selectFolder() {

    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setNameFilter("Epsi Compressed Format (*.ecf)");
    if( dialog.exec() == QFileDialog::Accepted ) {
        path_->setText(dialog.selectedFiles().first());
        currentFile_ = dialog.selectedFiles().first();
        currentFolder_ = dialog.directory();
        emit directoryChanged( currentFolder_ );
    }

}
void FileSelector::validateFolder() {
    QDir newDir( path_->text());
    if( newDir.exists() == false) {
        QMessageBox::critical(this, "Invalid folder",QString("%1 is not a valid folder").arg(path_->text()),QMessageBox::Ok);
        path_->setText(currentFolder_.absolutePath());
    }
    else {
        currentFolder_ = newDir;
        emit directoryChanged( currentFolder_ );
    }
}
const QDir &FileSelector::currentFolder()const {
    return currentFolder_;
}
const QString &FileSelector::currentFile()const {
    return currentFile_;
}
