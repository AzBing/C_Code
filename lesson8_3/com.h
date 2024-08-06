#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
 
#define PATHNAME "/home/zhb/lesson8_3" //路径名
#define PROJ_ID 0x6666 //整数标识符
#define SIZE 4096 //共享内存的大小

//#pragma once
// 
//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <string.h>
//#include <fcntl.h>
// 
//#define FILE_NAME "myfifo" //让客户端和服务端使用同一个命名管道
