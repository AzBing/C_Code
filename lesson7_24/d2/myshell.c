#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
  
  printf("我是父进程，我的PID是：%d\n",getpid());
  pid_t id = fork();
  
  if(id==0)
  {
    //子进程  
    
    printf("我是子进程，我的PID是：%d\n",getpid());
    char* const env_[] = {(char*)"MYPATH=YouCanSeeMe!!",NULL};
    execle("./mycmd","mycmd",NULL,env_);
  }
  
  int status = 0;
  sleep(3);
  
  id = waitpid(id,&status,0);
  printf("父进程等待成功,子进程PID：%d,返回值：%d,信号：%d\n",id,(status>>8)&0xff,status&0x7f);
  
  return 0;
}



//int main()
//{
//  printf("我是父进程，我的PID是：%d\n",getpid());
//  pid_t id = fork();
//  if(id==0)
//  {
//    //子进程  
//    printf("我是子进程，我的PID是：%d\n",getpid());
//    int ret = execl("/usr/bin/ls","ls","-a","-l",NULL);
//    printf("子进程创建替换失败：%d",ret);
//  }
//  int status = 0;
//  sleep(3);
//  
//  id = waitpid(id,&status,0);
//  printf("子进程等待成功,子进程PID：%d,返回值：%d,信号：%d\n",id,(status>>8)&0xff,status&0x7f);
//  
//  return 0;
//}
//
//int main()
//{
//  //ls -a-l
//  
//	printf("我是一个进程，我的PID是：%d\n",getpid());
//  //execl("/usr/bin/ls","ls","-a","-l",NULL);
//  int ret = execl("usr/bin/lssssss","ls","-a","-l",NULL);
//  printf("我执行完毕了，我的PID是：%d,ret:%d\n",getpid(),ret);
//  
//	return 0;
//}
//
