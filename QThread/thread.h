#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void run();
signals:
    void notify();
};

#endif // THREAD_H
