#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  pid_t id = fork();
  if(id!=0)
  {
    //father
    int cnt = 5;
    while(cnt)
    {
      printf("我是父进程，还剩下 %dS\n", cnt--);
      sleep(1);
    }
    printf("我是父进程，我已经结束了\n");
    _exit(0);
  }
  else 
  {
    //child
    while(1)
    {
      sleep(1);
    }
  }


 // pid_t id = fork();
 // if(id==0)
 // {
 //   //child
 //   int cnt = 5;
 //   while(cnt)
 //   {
 //     printf("我是子进程，还剩下 %dS\n", cnt--);
 //     sleep(1);
 //   }
 //   printf("我是子进程，我已经僵尸了，等待被检测\n");
 //   exit(0);
 // }
 // else 
 // {
 //   //father
 //   while(1)
 //   {
 //     sleep(1);
 //   }
 // }
                        


 // while(1)
 // {
 //   printf("hello linux!\n");
 //  sleep(1);
 // }
   // int ret = fork();
   // if(ret == 0)
   // { //如果子进程创建成功，给子进程返回0
   //     while(1)
   //     {                                                                
   //         printf("I am child!\n");
   //         sleep(1);
   //     }
   // }
   // else if(ret > 0)
   // { //如果子进程创建成功，给父进程返回子进程的pid
   //     while(1)
   //     {
   //       printf("I am father!\n");
   //       sleep(1);
   //     }
   // }
   // else
   // { //如果子进程创建失败，给父进程返回-1
   //     //fork error
   // }

                        
 // pid_t id = fork();
 // //id=0：子进程 ；  id>0：父进程
 // if(id == 0)//子进程
 // {  
 //   while(1)
 //   {
 //     printf("我是子进程，我的pid:%d, 我的父进程:%d\n",getpid(),getppid());
 //     sleep(1);
 //   }
 // }
 // else//父进程
 // { 
 //   while(1)
 //   {
 //     printf("我是父进程，我的pid:%d, 我的父进程:%d\n",getpid(),getppid());
 //     sleep(1);
 //   }
 // }


 // while(1)
 // {
 //   printf("I am a process!,pid:%d, ppid:%d\n",getpid(),getppid());
 //   sleep(1);

 // }
////  while(1)
//  {
//    printf("I am a process!,pid:%d\n",getpid());
//    sleep(1);
//
//  }
//
 // while(1)
 // {
 //   printf("I am process!\n");
 //   sleep(1);
 // }
  return 0;
}


