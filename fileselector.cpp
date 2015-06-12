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
    folder_ = new QLineEdit(currentFolder().absolutePath(), this);
    folder_->setEnabled(false);
    auto layout = new QHBoxLayout;
    layout->addWidget(folder_);
    layout->addWidget(button);

    connect(button, SIGNAL(clicked()),this, SLOT(selectFolder()));
    connect(folder_,SIGNAL(editingFinished()),this, SLOT(validateFolder()));

    setLayout(layout);
}
void FileSelector::selectFolder() {

    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    if( dialog.exec() == QFileDialog::Accepted ) {
        folder_->setText(dialog.selectedFiles().first());
        currentFolder_ = dialog.directory();
        emit directoryChanged( currentFolder_ );
    }

}
void FileSelector::validateFolder() {
    QDir newDir( folder_->text());
    if( newDir.exists() == false) {
        QMessageBox::critical(this, "Invalid folder",QString("%1 is not a valid folder").arg(folder_->text()),QMessageBox::Ok);
        folder_->setText(currentFolder_.absolutePath());
    }
    else {
        currentFolder_ = newDir;
        emit directoryChanged( currentFolder_ );
    }
}
const QDir &FileSelector::currentFolder()const {
    return currentFolder_;
}
