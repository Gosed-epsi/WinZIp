#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>

class Zipper : public QThread
{
    Q_OBJECT
public:
    explicit Zipper(QObject *parent = 0);

signals:

public slots:

};

#endif // ZIPPER_H
