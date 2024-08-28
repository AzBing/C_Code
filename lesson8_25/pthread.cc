#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t g_lock;
pthread_cond_t thread_a_cond,thread_b_cond;
int g_is_my_turn = 1;

void *thread_a_start(void *arg)
{
    (void)arg;
    while (1)
    {
        pthread_mutex_lock(&g_lock);
 
        while (g_is_my_turn == 1)
        {
            pthread_cond_wait(&thread_a_cond, &g_lock);
        }
 
        printf("hello thread A\n");
        sleep(1);
        g_is_my_turn++;
        pthread_mutex_unlock(&g_lock);
        pthread_cond_signal(&thread_b_cond);
    }
}

void *thread_b_start(void *arg)
{
    (void)arg;
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&g_lock);
        while (g_is_my_turn == 0)
        {
            pthread_cond_wait(&thread_b_cond, &g_lock);
        }
        printf("hello thread B\n");
        sleep(1);
        g_is_my_turn--;
        pthread_mutex_unlock(&g_lock);
        pthread_cond_signal(&thread_a_cond);
    }
}

int main()
{
    // 初始化

    pthread_mutex_init(&g_lock, NULL);
    pthread_cond_init(&thread_a_cond, NULL);
    pthread_cond_init(&thread_b_cond, NULL);
    // 定义两个线程
    pthread_t thread_a, thread_b;
    
    int ret = pthread_create(&thread_a, NULL, thread_a_start, NULL);
    if (ret < 0)
    {
        perror("pthread_create error");
        return 0;
    }
    ret = pthread_create(&thread_b, NULL, thread_b_start, NULL);
    if (ret < 0)
    {
        perror("pthread_create error");
        return 0;
    }
 
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_mutex_destroy(&g_lock);
    pthread_cond_destroy(&thread_a_cond);
    pthread_cond_destroy(&thread_b_cond);
    return 0;
}
