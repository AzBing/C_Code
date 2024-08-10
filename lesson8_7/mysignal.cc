#include <iostream>
#include <unistd.h>
#include <signal.h>

using namespace std;

void PrintPending(sigset_t &pending)
{
    for (int signo = 31; signo >= 1; signo--)
    {
        if (sigismember(&pending, signo))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n\n";
}

void handler(int signo)
{
    cout << "catch a signo: " << signo << endl;
}
int main()
{

    // 0. 对2号信号进行自定义捕捉
    signal(2, handler);

    // 1. 先对2号信号进行屏蔽 --- 数据预备
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    sigaddset(&bset, 2);
    // 1.2 调用系统调用，将数据设置进内核
    sigprocmask(SIG_SETMASK, &bset, &oset);

    // 2. 重复打印当前进程的pending
    sigset_t pending;
    int cnt = 0;
    while (true)
    {
        // 2.1 获取
        int n = sigpending(&pending);
        if (n < 0)
            continue;
        // 2.2 打印
        PrintPending(pending);

        sleep(1);
        cnt++;
        // 2.3 解除阻塞
        if(cnt == 20)
        {
            cout << "unblock 2 signo" << endl;
            sigprocmask(SIG_SETMASK, &oset, nullptr);
        }
    }
    // 3 发送2号 0000000000000000000000010

    return 0;
}