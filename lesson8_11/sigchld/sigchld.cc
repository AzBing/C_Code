#include <iostream>
#include <signal.h>
#include <unistd.h>
 
using namespace std;
 
int main()
{
    signal(SIGCHLD, SIG_IGN);
    pid_t id = fork();
    if (id == 0)
    {
        // 子进程
        cout << "我是子进程: pid: " << getpid() << endl;
        sleep(5);
        exit(0);
    }
    while (true)
    {
        cout << "我是父进程: pid: " << getpid() << endl;
        sleep(1);
    }
 
    return 0;
}