#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#define NUM 4

class threadData
{
public:
    threadData(int number , pthread_mutex_t *mutex)
    {
        threadname = "thread-" + to_string(number);
        lock = mutex;
    }

public:
    string threadname;
    pthread_mutex_t *lock;
};

int tickets = 2000; // 用多线程，模拟一轮抢票

void *getTicket(void *args)
{
    threadData *td = static_cast<threadData *>(args);
    const char *name = td->threadname.c_str();
    while (true)
    {
        // 线程对于锁的竞争能力可能会不同 --- 一会由例子
        // pthread_mutex_lock(td->lock); // 申请锁成功，才能往后执行，不成功，阻塞等待。
        pthread_mutex_lock(&lock); // 申请锁成功，才能往后执行，不成功，阻塞等待。
        if(tickets > 0)
        {
            usleep(1000);
            printf("who=%s, get a ticket: %d\n", name, tickets); // ?
            tickets--;
            // pthread_mutex_unlock(td->lock);
            pthread_mutex_unlock(&lock);
        }
        else{
            // pthread_mutex_unlock(td->lock);
            pthread_mutex_unlock(&lock);

            break;
        }
        usleep(13); // 我们抢到了票，我们会立马抢下一张吗？其实多线程还要执行得到票之后的后续动作。usleep模拟
    }
    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    pthread_mutex_init(&lock, nullptr);

    vector<pthread_t> tids;
    vector<threadData *> thread_datas;
    for (int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        threadData *td = new threadData(i , &lock);
        thread_datas.push_back(td);
        pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
        tids.push_back(tid);
    }

    for (auto thread : tids)
    {
        pthread_join(thread, nullptr);
    }

    for (auto td : thread_datas)
    {
        delete td;
    }

    pthread_mutex_destroy(&lock);
    return 0;
}