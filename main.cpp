#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //EpsiFileCompressor *epsiFileCompressor = new EpsiFileCompressor();
    //epsiFileCompressor->compress("C:/Users/Public/Pictures","COMPRESS");
    //epsiFileCompressor->uncompress("/Users/sinys/EPSI/IA/Compress.ecf", "/Users/sinys/EPSI/IA");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
