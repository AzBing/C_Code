#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void PrintPending()
{
    sigset_t set;
    sigpending(&set);

    for (int signo = 1; signo <= 31; signo++)
    {
        if (sigismember(&set, signo))
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
}

void handler(int signo)
{
    cout << "catch a signal, signal number : " << signo << endl;
    while (true)
    {
        PrintPending();
        sleep(1);
    }
}
int main()
{
    struct sigaction act, oact;
    memset(&act, 0, sizeof(act));
    memset(&oact, 0, sizeof(oact));

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, 1);
    sigaddset(&act.sa_mask, 3);
    sigaddset(&act.sa_mask, 4);
    act.sa_handler = handler; // SIG_IGN SIG_DFL
    sigaction(2, &act, &oact);

    while (true)
    {
        cout << "I am a process: " << getpid() << endl;
        sleep(1);
    }

    return 0;
}