#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    EpsiFileCompressor *epsiFileCompressor = new EpsiFileCompressor();
    QString name = "/Users/sinys/sans_titre/Test.ecf";
    QString nameTwo = "/Users/sinys/sans_titre";
    //epsiFileCompressor->compress("C:/Users/Public/Pictures","COMPRESS");
    epsiFileCompressor->uncompress(name, nameTwo);

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
