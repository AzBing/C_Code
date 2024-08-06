//my_client.cxx
#include "com.h"
 
int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID); //获取与server进程相同的key值
	if (key < 0) {
		perror("ftok");
		return 1;
	}
	int shm = shmget(key, SIZE, IPC_CREAT); //获取server进程创建的共享内存的用户层id
	if (shm < 0) {
		perror("shmget");
		return 2;
	}
 
	char* mem = (char*)shmat(shm, NULL, 0); //关联共享内存
 
    //客户端向共享内存写入数据
    int i = 0;
    while (1) {
	    mem[i++] = 'A' + i;
	    mem[i] = '\0';
	    sleep(1);
    }
 
	shmdt(mem); //共享内存去关联
	return 0;
}


//``//my_client.cc
//``#include "com.h"
//`` 
//``int main()
//``{
//``	int fd = open(FILE_NAME, O_WRONLY); //以写的方式打开命名管道文件
//``	if (fd < 0) {
//``		perror("open");
//``		return 1;
//``	}
//``	char msg[128];
//``	while (1){
//``        memset(msg,'\0',sizeof(msg));
//``		printf("Please Enter :>");
//``        fflush(stdout);//printf字符串中没有'\n'
//``		ssize_t s = read(0, msg, sizeof(msg)-1);//从标准输出流文件中读取
//``		if (s > 0) {
//``			write(fd, msg, strlen(msg));
//``		}
//``	}
//``	close(fd);
//``	return 0;
//``}
