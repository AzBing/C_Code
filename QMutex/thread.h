#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QWidget>
#include <QMutex>
class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    static int num;
    static QMutex mutex;

    void run();
};

#endif // THREAD_H
