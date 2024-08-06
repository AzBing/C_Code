#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd[2] = { 0 };
	if (pipe2(fd , O_NONBLOCK) < 0) {
		perror("pipe");
		return 1;
	}
 
	pid_t id = fork();
	if (id == 0) { //child 
		close(fd[0]); //子进程关闭读端
		char c = 'a';
		int count = 0;
		while (1) {
            int num = write(fd[1], &c, 1);
            if(num == -1) break;
			count++;
		}
        printf("%d\n", count); //打印当前写入的字节数
		close(fd[1]);
		exit(0);
	}
    else if(id > 0) {//father
        close(fd[1]);
	    waitpid(id, NULL, 0);
	    close(fd[0]);
    }
    else {
        perror("fork");
        exit(0);
    }
 
	return 0;
}



//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//int main()
//{
//    int fd[2] = {0};
//    if (pipe(fd) < 0) {
//        perror("pipe");
//        return 1;
//    }
// 
//    pid_t id = fork();
//    if (id == 0) { // child
//        close(fd[0]);
//        const char *msg = "hello father, I am child...";
//        for (int i = 0; i < 10; ++i) {
//            write(fd[1], msg, strlen(msg));
//            sleep(1);
//        }
//        close(fd[1]);
//        exit(0);
//    }
//    else if (id > 0) { // father
//        close(fd[1]);
//        close(fd[0]); //父进程直接关闭读端（导致子进程被操作系统杀死）
//        int status = 0;
//        waitpid(id, &status, 0);
//        printf("child get signal:%d\n", WTERMSIG(status));
//    }
// 
//    return 0;
//}


//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#define FILE_NAME "myfifo"
// 
//int main()
//{
//	umask(0); //将文件默认掩码设置为0
//	if (mkfifo(FILE_NAME, 0666) < 0) {
//		perror("mkfifo");
//		return 1;
//	}
//	//... ...
//	return 0;
//}
//


//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//int main()
//{
//    int fd[2] = { 0 };
//    if (pipe(fd) < 0) { 
//        perror("pipe");
//        return 1;
//    }
// 
//    pid_t id = fork();
//    if (id == 0){
//        close(fd[0]);
//        const char* msg = "hello father, I am child...";
//        int count = 10;
//        while (count--){
//            write(fd[1], msg, strlen(msg));
//            sleep(1);
//        }
//        close(fd[1]);
//        exit(0);
//    }
//    else if(id > 0) {
//        close(fd[1]);
//        char buff[64] = {'\0'};
//        while (1){
//            ssize_t s = read(fd[0], buff, sizeof(buff));
//            if (s > 0){
//                buff[s] = '\0';
//                printf("child send to father:%s\n", buff);
//            }
//            else if (s == 0){
//                printf("read file end\n");
//                break;
//            }
//            else{
//                printf("read error\n");
//                break;
//            }
//        }
//        close(fd[0]);
//        waitpid(id, NULL, 0);
//    }
// 
//    return 0;
//}
