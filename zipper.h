#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>

class Zipper : public QThread
{
public:
    Zipper(QString &file);
};

#endif // ZIPPER_H
