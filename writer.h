#ifndef WRITER_H
#define WRITER_H

#include <QThread>

class Writer : public QThread
{
    Q_OBJECT
public:
    explicit Writer(QObject *parent = 0);

signals:

public slots:

};

#endif // WRITER_H
