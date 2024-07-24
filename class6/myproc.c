#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int g_val = 100;
int main()
{
  pid_t id = fork();
  if(id==0)
  {
    //child
    int falg = 0;
    while(1)
    {
      printf("我是子进程:%d, ppid:%d, g_val:%d, &g_val:%p\n\n",getpid(),getppid(),g_val,&g_val);
      sleep(1);
      falg++;
      if(falg == 2)
      {
        g_val = 200;
        printf("我是子进程，全局变量已被我修改\n");
      }
    }
  }
  else 
  {
    while(1)
    {
      //parent
      printf("我是父进程:%d, ppid:%d, g_val:%d, &g_val:%p\n\n",getpid(),getppid(),g_val,&g_val);
      sleep(1);
    }
  }
}

