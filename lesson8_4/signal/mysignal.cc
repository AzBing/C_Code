#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void mysignal(int signu)
{
    cout << "process get a signal: " << signu << endl;

}
int main()
{
    // signal(SIGINT, mysignal); // 只需要设置一次，往后都有效！
    // signal(3, mysignal);
    signal(19, mysignal);
    // 信号的产生和我们自己的代码的运行时异步的

    for(int i = 1; i <= 31; i++)
    {
        signal(i, mysignal);
    }

    while(true)
    {
        cout << "I am a crazy process : " << getpid() << endl;
        sleep(1);
    }
}
// int main()
// {
//     signal(SIGINT,mysignal);

//     while(true)
//     {
//         cout << "I am a crazy process" << endl;
//         sleep(1);
//     }

//     return 0;
// }