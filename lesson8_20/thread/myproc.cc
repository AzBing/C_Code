#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>


void* Routine(void* arg)
{
	pthread_detach(pthread_self());
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	while (1){
		printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
		sleep(1);
	}
	return 0;
}


// void* Routine(void* arg)
// {
// 	char* msg = (char*)arg;
// 	int count = 0;
// 	while (count < 5){
// 		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
// 		sleep(1);
// 		count++;
// 		pthread_cancel(pthread_self());
// 	}
// 	pthread_exit((void*)6666);
// }
// int main()
// {
// 	pthread_t tid[5];
// 	for (int i = 0; i < 5; i++){
// 		char* buffer = (char*)malloc(64);
// 		sprintf(buffer, "thread %d", i);
// 		pthread_create(&tid[i], NULL, Routine, buffer);
// 		printf("%s tid is %lu\n", buffer, tid[i]);
// 	}
// 	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
// 	for (int i = 0; i < 5; i++){
// 		void* ret = NULL;
// 		pthread_join(tid[i], &ret);
// 		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int*)ret);
// 	}
// 	return 0;
// }


// void* Routine(void* arg)
// {
// 	char* msg = (char*)arg;
// 	int count = 0;
// 	while (count < 5){
// 		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
// 		sleep(1);
// 		count++;
// 	}
// 	pthread_exit((void*)6666);
// }
// int main()
// {
// 	pthread_t tid[5];
// 	for (int i = 0; i < 5; i++){
// 		char* buffer = (char*)malloc(64);
// 		sprintf(buffer, "thread %d", i);
// 		pthread_create(&tid[i], NULL, Routine, buffer);
// 		printf("%s tid is %lu\n", buffer, tid[i]);
// 	}
// 	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
// 	for (int i = 0; i < 5; i++){
// 		void* ret = NULL;
// 		pthread_join(tid[i], &ret);
// 		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int*)ret);
// 	}
// 	return 0;
// }


// void* Routine(void* arg)
// {
// 	char* msg = (char*)arg;
// 	while (1){
// 		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
// 		sleep(1);
// 	}
// 	return (void*)0;
// }
// int main()
// {
// 	pthread_t tid[5];
// 	for (int i = 0; i < 5; i++){
// 		char* buffer = (char*)malloc(64);
// 		sprintf(buffer, "thread %d", i);
// 		pthread_create(&tid[i], NULL, Routine, buffer);
// 		printf("%s tid is %lu\n", buffer, tid[i]);
// 	}
// 	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());

// 	return 0;
// }


 
// using namespace std;
 
// void* Routine(void *args)
// {
//     cout << (char*)args << endl;
//     sleep(3);
//     return (void*)0;
// }
// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, nullptr, Routine, (void*)"new thread");
    
//     void* ret = nullptr;
//     int n = pthread_join(tid,&ret);
//     if(n == 0) {
//         cout << "等待成功" << endl;
//         cout << "返回信息为: " <<(long long)ret << endl;
//     }
//     else {
//         cout << "等待失败" << endl;
//     }
 
//     return 0;
// }

// void* Routine(void* arg)
// {
// 	char* msg = (char*)arg;
// 	while (1){
// 		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
// 		sleep(1);
// 	}
// }
// int main()
// {
// 	pthread_t tid[5];
// 	for (int i = 0; i < 5; i++){
// 		char* buffer = (char*)malloc(64);
// 		sprintf(buffer, "thread %d", i);
// 		pthread_create(&tid[i], NULL, Routine, buffer);
// 		printf("%s tid is %lu\n", buffer, tid[i]);
// 	}
// 	while (1){
// 		 printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
// 		 sleep(2);
// 	}
// 	return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <sys/types.h>

// void* Routine(void* arg)
// {
// 	char* msg = (char*)arg;
// 	while (1){
// 		printf("I am %s...pid: %d, ppid: %d\n", msg, getpid(), getppid());
// 		sleep(1);
// 	}
// }
// int main()
// {
// 	pthread_t tid[5];
// 	for (int i = 0; i < 5; i++){
// 		char* buffer = (char*)malloc(64);
// 		sprintf(buffer, "thread %d", i);
// 		pthread_create(&tid[i], NULL, Routine, buffer);
// 	}
// 	while (1){
// 		printf("I am main thread...pid: %d, ppid: %d\n", getpid(), getppid());
// 		sleep(2);
// 	}
// 	return 0;
// }


 
// int g_val = 100;
// int main()
// {
// 	pid_t id = vfork();
// 	if (id == 0) 
//     {
//         //child
// 		g_val = 200;
// 		cout << "child:PID:" << getpid() << " PPID:"<< getppid() << " g_val:" <<  g_val << endl;
//     	exit(0);
// 	}
    
// 	//father
// 	sleep(3);
// 	cout << "father:PID:" << getpid() << " g_val:" <<  g_val << endl;
// 	return 0;
// }
