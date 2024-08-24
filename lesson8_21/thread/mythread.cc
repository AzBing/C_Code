#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdio>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex;
pthread_cond_t cond;
void* Routine(void* arg)
{
	pthread_detach(pthread_self());
	std::cout << (char*)arg << " run..." << std::endl;
	while (true){
		pthread_cond_wait(&cond, &mutex); //阻塞在这里，直到被唤醒
		std::cout << (char*)arg << "活动..." << std::endl;
	}
}
int main()
{
	pthread_t t1, t2, t3;
	pthread_mutex_init(&mutex, nullptr);
	pthread_cond_init(&cond, nullptr);
	
	pthread_create(&t1, nullptr, Routine, (void*)"thread 1");
	pthread_create(&t2, nullptr, Routine, (void*)"thread 2");
	pthread_create(&t3, nullptr, Routine, (void*)"thread 3");
	
	while (true){
		getchar();
		pthread_cond_broadcast(&cond);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}



// void *Routine(void *pmtx)
// {
//     pthread_mutex_lock((pthread_mutex_t*)pmtx);
//     pthread_mutex_lock((pthread_mutex_t*)pmtx);
//     pthread_mutex_unlock((pthread_mutex_t*)pmtx);//无法执行
//     pthread_exit(nullptr);
// }
// int main()
// {
//     pthread_mutex_t mtx;
//     pthread_mutex_init(&mtx, nullptr);
 
//     pthread_t tid;
//     pthread_create(&tid, nullptr, Routine, (void *)&mtx);
 
//     pthread_join(tid, NULL);//等待不到
// 	pthread_mutex_destroy(&mtx);
//     return 0;
// } 

// const int thread_num = 4;
// int tickets = 1000;
// pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
 
// void* GetTickets(void* args) {
// 	while (true) {
//         pthread_mutex_lock(&mtx);
// 		if (tickets > 0) {
// 			usleep(1000);//抢票所耗费的时间
//             printf("[%s] get a ticket, left: %d\n", (char*)args, --tickets);
//             pthread_mutex_unlock(&mtx);
//             usleep(10);//避免全部为同一线程抢占锁
// 		}
// 		else {
//             pthread_mutex_unlock(&mtx);
// 			break;
// 		}
// 	}
// 	printf("%s quit!\n", (char*)args);
// 	pthread_exit((void*)0);
// }
// int main()
// {
//     pthread_t tids[thread_num];
//     pthread_create(tids, nullptr, GetTickets, (void*)"thread 1");
//     pthread_create(tids + 1, nullptr, GetTickets, (void*)"thread 2");
// 	pthread_create(tids + 2, nullptr, GetTickets, (void*)"thread 3");
// 	pthread_create(tids + 3, nullptr, GetTickets, (void*)"thread 4");
 
//     for(int i = 0;i < thread_num; ++i) {
//         pthread_join(tids[i], nullptr);
//     }
//     return 0;
// } 


// const int thread_num = 4;
// int tickets = 1000;
 
// void* GetTickets(void* args) {
// 	while (true) {
// 		if (tickets > 0) {
// 			usleep(10000);//抢票所耗费的时间
//             printf("[%s] get a ticket, left: %d\n", (char*)args, --tickets);
// 		}
// 		else {
// 			break;
// 		}
// 	}
// 	printf("%s quit!\n", (char*)args);
// 	pthread_exit((void*)0);
// }
// int main()
// {
//     pthread_t tids[thread_num];
//     pthread_create(tids, nullptr, GetTickets, (void*)"thread 1");
//     pthread_create(tids + 1, nullptr, GetTickets, (void*)"thread 2");
// 	pthread_create(tids + 2, nullptr, GetTickets, (void*)"thread 3");
// 	pthread_create(tids + 3, nullptr, GetTickets, (void*)"thread 4");
 
//     for(int i = 0;i < thread_num; ++i) {
//         pthread_join(tids[i], nullptr);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>

// int count = 0;
// void* Routine(void* arg)
// {
// 	while (1){
// 		count++;
// 		sleep(1);
// 	}
// 	pthread_exit((void*)0);
// }
// int main()
// {
// 	pthread_t tid;
// 	pthread_create(&tid, NULL, Routine, NULL);
// 	while (1){
// 		printf("count: %d\n", count);
// 		sleep(1);
// 	}
// 	pthread_join(tid, NULL);
// 	return 0;
// }
