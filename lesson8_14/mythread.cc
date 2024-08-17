#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;


std::string toHex(pthread_t tid)
{
    char hex[64];
    snprintf(hex, sizeof(hex), "%p", tid);
    return hex;
}

void *threadRoutine(void *args)
{
    while(true)
    {
        cout << "thread id: " << toHex(pthread_self()) << endl;
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, threadRoutine, (void*)"thread 1");

    cout << "main thread create thead done, new thread id : " << toHex(tid) << endl;
    pthread_join(tid, nullptr);

    return 0;
}

// int g_val = 100;

// void *threadRoutine(void *args)
// {
//     const char *name = (const char*)args;
//     int cnt = 5;
//     while (true)
//     {
//         printf("%s,  pid: %d, g_val: %d, &g_val: 0x%p\n", name,getpid(), g_val, &g_val);
//         // cout << "new thread, pid: " << getpid() << endl;
//         // show("[new thread]");
//         sleep(1);

//         // int a = 10;
//         // a /= 0;
//         cnt--;
//         if(cnt == 0) break;
//     }

// }

// int main()
// {
//     // PTHREAD_CANCELED;
//     pthread_t tid;
//     pthread_create(&tid, nullptr, threadRoutine, (void*)"Thread 1");

//     sleep(1);
//     pthread_cancel(tid);

//     // sleep(1);
//     // return 0;
//     // while (true)
//     // {
//     //     printf("main thread pid: %d, g_val: %d, &g_val: 0x%p, create new thread tid: %p\n", getpid(), g_val, &g_val, tid);
//     //     // cout << "main thread, pid: " << getpid() << ", g_val: " << g_val << ", &g_val:" << &g_val << endl;
//     //     // show("[main thread]");
//     //     sleep(1);
//     //     g_val++;
//     // }
//     // sleep(7);
//     void *retval;
//     pthread_join(tid, &retval);

//     cout << "main thread quit ..., ret: " << (long long int)retval << endl;
//     return 0;
// }