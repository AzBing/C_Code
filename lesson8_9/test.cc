#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;
 
void handler(int signum) {
	cout << "handler signo: " << signum << endl;
}
void PrintPending(sigset_t *pending)
{
	for (int i = 1; i <= 31; i++) {
		if (sigismember(pending, i)) cout << "1 ";
		else cout << "0 ";
	}
	cout << endl;
}
int main()
{
	signal(2, handler);
 
	sigset_t set, oset;
    sigset_t pending;
    //清空信号集
	sigemptyset(&set);
	sigemptyset(&oset);
    sigemptyset(&pending);
 
	sigaddset(&set, 2);//添加2号信号
	sigprocmask(SIG_SETMASK, &set, &oset);//将数据设置进内核，阻塞2号信号
 
	int count = 0;
	while (1) {
		sigpending(&pending); //获取pending
		PrintPending(&pending); //打印pending位图
		sleep(1);
		++count;
 
		if(count == 20) { //恢复曾经的信号屏蔽字
			sigprocmask(SIG_SETMASK, &oset, NULL);
			cout << "恢复信号屏蔽字" << endl;
		}
	}
	return 0;
}

// #include <stdio.h>
// int main() 
// {
//     printf("I am running!!!\n");
//     int* ptr = NULL;
//     *ptr = 100;
//     return 0;
// }

// //减少IO后的代码
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>
 
// int count = 0;
// void handler(int signum) {
//     printf("get a signal: %d\n", signum);
//     printf("count: %d\n", count);
//     exit(0);
// }
// int main()
// {
//     signal(SIGALRM, handler);
// 	alarm(1);
// 	while (1) {
// 		count++;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <unistd.h>
// #include <cstring>
// #include <cstdlib>
// #include <sys/types.h>
// #include <sys/wait.h>
// using namespace std;
 
// int main()
// {
//     //使用pipe创建匿名管道
// 	int fd[2] = { 0 };
// 	if (pipe(fd) < 0) {
// 		perror("pipe");
// 		exit(1);
// 	}
 
// 	pid_t id = fork();
// 	if (id == 0) { //child
// 		close(fd[0]);
// 		const char* msg = "hello father, I am child...";
//         for(int i = 0;i < 10; ++i) {
//             write(fd[1], msg, strlen(msg));
// 			sleep(1);
//         }
// 		close(fd[1]);
// 		exit(0);
// 	}
//     else if(id > 0) { //father
//         close(fd[1]);
// 	    close(fd[0]);
// 	    int status = 0;
// 	    waitpid(id, &status, 0);
// 	    cout << "child get signal:" << WTERMSIG(status) << endl; //打印子进程收到的信号
//     }
//     else {
//         perror("fork error");
//         exit(1);
//     }
	
// 	return 0;
// }

// #include <iostream>
// #include <cstdlib>
// #include <signal.h>
// #include <unistd.h>
// using namespace std;
 
// void handler(int signum) {
//     cout << "get a signal : " << signum << endl;
// }
// int main()
// {
//     signal(SIGABRT,handler);
 
//     while(true) {
//         sleep(1);
//         abort();
//     }
//     return 0;
// }


// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <sys/types.h>
// #include <signal.h>
 
// void Usage(const char* str) {
//     std::cout << "Usage : " << str << "pid signo" << std::endl;   
// }

// int main(int argc, char* argv[]) 
// {
//     if(argc < 3) {
//         Usage(argv[0]);
//     }
 
//     int signum = atoi(argv[1]);
 
//     std::vector<pid_t> v;
//     for(int i = 2; i < argc; ++i) {
//         v.push_back(atoi(argv[i]));
//     }
 
//     for(auto &e : v) {
//         kill(e, signum);
//     }
//     return 0;
// }



// #include <iostream>
// #include <signal.h>
// #include <unistd.h>

// void handler(int signum) {
//     std::cout << "get a signal : " << signum << std::endl;
// }

// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <sys/types.h>
// using namespace std;
// int main()
// {
// 	if (fork() == 0) {//child
// 		std::cout << "I am running..." << std::endl;
// 		int *p = nullptr;
// 		*p = 100;//野指针
// 		exit(0);
// 	}
// 	//father
// 	int status = 0;
// 	waitpid(-1, &status, 0);
//     std::cout << "exit_code:" << WEXITSTATUS(status) << std::endl;
//     std::cout << "core_dump:" << WCOREDUMP(status) << std::endl;
//     std::cout << "trem_signal:" << WTERMSIG(status) << std::endl;
	
// 	return 0;
// }

// #include <iostream>
// #include <unistd.h>
// int main()
// {
//     std::cout << "I am running!!!" << std::endl;
//     sleep(3);
//     int err = 10 / 0;//除0错误
//     return 0;
// }

// int main()
// {
//     signal(2, handler);
//     while (1) {
// 		std::cout << "hello signal!" << std::endl;
// 		sleep(1);
// 	}
//     return 0;
// }