#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>
using namespace std;
 
int main()
{
	signal(SIGCHLD, SIG_IGN);
	if (fork() == 0) { //child
		cout << "child is running, PID: " << getpid() << endl;
		sleep(3);
		exit(1);
	}
	//father
	while (1);
 
	return 0;
}

// #include <iostream>
// #include <cstdlib>
// #include <unistd.h>
// #include <signal.h>
// #include <sys/wait.h>
// using namespace std;
 
// void handler(int signo)
// {
// 	cout << "get a signal:" << signo << endl;
// 	int ret = 0;
// 	while ((ret = waitpid(-1, NULL, WNOHANG)) > 0) {
// 		cout << "wait child " << ret << " success" << endl;
// 	}
//     exit(0);
// }
// int main()
// {
// 	signal(SIGCHLD, handler);
// 	if (fork() == 0) {//child
// 		cout << "child is running, PID: " << getpid() << endl;
// 		exit(1);
// 	}
// 	//father
// 	while (1);
 
// 	return 0;
// }