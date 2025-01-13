#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    // run 方法中,由于线程安全问题,不能直接进行修改界面内容
    // 可以针对时间来进行计时,通过信号槽,来通知主线程,负责更新内容
    for(int i = 0; i < 10; i++)
    {
        sleep(1);
        emit notify();
    }
}
