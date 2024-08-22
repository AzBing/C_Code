#include <iostream>
#include <unistd.h>
#include <pthread.h>

int cnt = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *Count(void * args)
{
    pthread_detach(pthread_self());
    uint64_t number = (uint64_t)args;
    std::cout << "pthread: " << number << " create success" << std::endl;

    while(true)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        std::cout << "pthread: " << number << " , cnt: " << cnt++ << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    for(uint64_t i = 0; i < 5; i++)
    {
        pthread_t tid;
        pthread_create(&tid, nullptr, Count, (void*)i);
        usleep(1000);
    }
    sleep(3);
    std::cout << "main thread ctrl begin: " << std::endl;

    while(true) 
    {
        sleep(1);
        // pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);
        std::cout << "signal one thread..." << std::endl;
    }

    return 0;
}