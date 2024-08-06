//my_server.cxx
#include "com.h"
 
int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
	if (key < 0) {
		perror("ftok");
		return 1;
	}
 
	int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); //创建新的共享内存
	if (shm < 0) {
		perror("shmget");
		return 2;
	}
 
	char* mem = (char*)shmat(shm, NULL, 0); //关联共享内存
 
    //服务端不断读取共享内存当中的数据并输出
    while (1) {
	    printf("client# %s\n", mem);
	    sleep(1);
    }
 
	shmdt(mem); //共享内存去关联
 
	shmctl(shm, IPC_RMID, NULL); //释放共享内存
	return 0;
}


////my_server.cc
//#include "com.h"
// 
//int main()
//{
//	umask(0);
//	if (mkfifo(FILE_NAME, 0666) < 0) {
//		perror("mkfifo");
//		return 1;
//	}
// 
//	int fd = open(FILE_NAME, O_RDONLY); //以读的方式打开命名管道文件
//	if (fd < 0) {
//		perror("open");
//		return 1;
//	}
// 
//	char msg[128] = {0};
//	while (1){
//		memset(msg,'\0',128);
//		ssize_t s = read(fd, msg, sizeof(msg)-1);
//		if (s > 0) {
//			printf("client: %s", msg);
//		}
//		else if (s == 0) {
//			printf("client quit!\n");
//			break;
//		}
//		else {
//			printf("read error!\n");
//			break;
//		}
//	}
//	close(fd);
//    unlink(FILE_NAME);
//	return 0;
//}
