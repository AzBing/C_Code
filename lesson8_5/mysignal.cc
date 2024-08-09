#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

void work()
{
    cout << "print log..." << endl;
}

// 信号为什么会一直被触发？？
void handler(int signo)
{
    // work();
    cout << "...get a sig, number: " << signo <<endl; // 打印消息
    // exit(1);
    int n = alarm(5);
    cout << "剩余时间：" << n << endl;
}

int main()
{
    signal(SIGALRM, handler);
    int n = alarm(50);

    while(1)
    {
        cout << "proc is running..., pid: " << getpid() << endl;
        sleep(1);
    }

    // signal(SIGSEGV, handler);
    // cout << "point error before" << endl;

    // sleep(5);
    // char buffer[1024];
    // int n =1024;
    // n = read(4, buffer, n);
    // printf("n=%d\n", n);
    // perror("read");
    // // int *p = nullptr;
    // // *p = 100;  // 野指针

    // // int a = 10;
    // // a /= 0; // 异常
    // cout << "point error before" << endl;

    sleep(1);

    return 0;
}