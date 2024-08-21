#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include "LockGuard.hpp"

using namespace std;

#define NUM 3

// int *p = NULL;

// __thread int g_val = 100;
__thread unsigned int number = 0;
__thread int pid = 0;

struct threadData
{
    string threadname;
};

// __thread threadData td;

string toHex(pthread_t tid)
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "0x%x", tid);
    return buffer;
}

void InitThreadData(threadData *td, int number)
{
    td->threadname = "thread-" + to_string(number); // thread-0
}

// 所有的线程，执行的都是这个函数？
void *threadRoutine(void *args)
{
    pthread_detach(pthread_self());

    // int test_i = 0;
    threadData *td = static_cast<threadData *>(args);
    // if(td->threadname == "thread-2") p = &test_i;
    string tid = toHex(pthread_self());
    int pid = getpid();

    int i = 0;
    while (i < 10)
    {
        cout << "tid: " << tid << ", pid: " << pid << endl;

        // cout << "pid: " << getpid() << ", tid : "
        //     << toHex(number) << ", threadname: " << td->threadname
        //         << ", g_val: " << g_val << " ,&g_val: " << &g_val <<endl;
        sleep(1);
        i++;
    }

    delete td;
    return nullptr;
}

int main()
{
    // 创建多线程！
    vector<pthread_t> tids;
    for (int i = 0; i < NUM; i++)
    {
        pthread_t tid;
        threadData *td = new threadData;
        InitThreadData(td, i);

        pthread_create(&tid, nullptr, threadRoutine, td);
        tids.push_back(tid);
        //sleep(1);
    }
    sleep(1); // 确保复制成功

    // for(auto i : tids)
    // {
    //     pthread_detach(i);
    // }
    // cout << "main thread get a thread local value, val: " << *p << ", &val: " << p << endl;

    for (int i = 0; i < tids.size(); i++)
    {
        int n = pthread_join(tids[i], nullptr);
        printf("n = %d, who = 0x%x, why: %s\n", n, tids[i], strerror(n));
    }

    return 0;
}