#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        //child
        printf("我是子进程，我正在运行...PID: %d\n", getpid());
        sleep(5);
        return 123;
    }
    else
    {
        int status = 0;
        printf("我是父进程，我正在运行...PID: %d\n", getpid());
        // sleep(20);
        while (1)
        {
            pid_t res = waitpid(id, &status, WNOHANG);
            if (res > 0)
            {
                printf("等待成功，res:%d,我所等待的子进程的退出码：%d,退出信号：%d\n", res, (status >> 8) & 0xff, status & 0x7f);
                return 0;
            }
            else if (res == 0)
            {
                //等待成功，但子进程没有退出
                printf("子进程好了没？没好，那我父进程先做其他事\n");
                sleep(1);
            }
            else
            {
                //出错了，暂时不处理
            }
        }
    }
}


//int main()
//{
//    pid_t id = fork();
//    if (id == 0)
//    {
//        //child
//        while (1)
//        {
//            printf("我是子进程，我正在运行...PID: %d\n", getpid());
//            sleep(1);
//        }
//    }
//    else
//    {
//        int status = 0;
//        printf("我是父进程，我正在运行...PID: %d\n", getpid());
//        // sleep(20);
//        pid_t res = waitpid(id, &status, 0);
//        if (res > 0)
//        {
//            printf("等待成功，res:%d,我所等待的子进程的退出码：%d,退出信号：%d\n", res, (status >> 8) & 0xff, status & 0x7f);
//        }
//        else if (res < 0)
//        {
//            printf("等待失败\n");
//        }
//    }
//}
//
//int main()
//{
//    pid_t id = fork();
//    if (id == 0)
//    {
//        //child
//        int cnt = 5;
//        while (cnt)
//        {
//            printf("我是子进程，我正在运行...PID: %d\n", getpid());
//            sleep(1);
//            cnt--;
//        }
//        exit(13);
//    }
//    else
//    {
//        int status = 0;
//        printf("我是父进程，我正在运行...PID: %d\n", getpid());
//        // sleep(20);
//        pid_t res = waitpid(id, &status, 0);
//        if (res > 0)
//        {
//            printf("等待成功，res:%d,\
//                   我所等待的子进程的退出码：%d\n", res, (status >> 8) & 0xff);
//        }
//        else if (res < 0)
//        {
//            printf("等待失败\n");
//        }
//    }
//}
//

//int main()
//{
//  pid_t id = fork();
//  if(id==0)
//  {
//    //child
//    while(1)
//    {
//      printf("我是子进程，我正在运行...PID: %d\n",getpid());
//      sleep(1);
//    }
//  }
//  else
//  {  
//      //fater
//      printf("我是父进程，我正在运行...PID: %d\n",getpid());
//      sleep(20);
//      pid_t ret = wait(NULL);
//      if(ret < 0)
//      {
//        printf("等待失败\n");
//      }
//      else 
//      {
//        printf("等待成功，result：%d\n",ret);
//      }
//      sleep(20);
//  }
//}




//void func()
//{
//  printf("hello func()\n");
//  exit(111);
//}

//int main()
//{
//  printf("hello exit");
//  //func();
//  _exit(0);
//  return 10;
//}
//

//int main()
//{
//  printf("hello Linux!\n");
//  
//  return 123;
//}
//
