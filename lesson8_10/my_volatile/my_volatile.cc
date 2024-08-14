#include <iostream>
#include <signal.h>
#include <unistd.h>
 
using namespace std;
 
volatile int flag = 0;
 
void hander(int signum)
{
    (void)signum;
    cout << "change flag: " << flag;
    flag = 1;
    cout << "->" << flag << endl;
}
 
int main()
{
    signal(2, hander);
    while (!flag);
    cout << "进程退出后flag: " << flag << endl;
    return 0;
}