#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define N 10

//int main()
//{

  //pid_t id = fork();
  //if(id < 0)
  //{
  //  perror("fork");
  //  return 1;
  //}
  //else if(id == 0)
  //{
  //  int cnt = 5;
  //  while(cnt)
  //  {
  //    printf("I am child ,pid:%d,ppid:%d,cnt:%d\n",getpid(),getppid(),cnt);
  //    cnt--;
  //    sleep(1);

  //  }
  //  exit(0);
  //}
  //else
  //{
  //  int cnt = 10;
  //  while(cnt)
  //  {
  //    printf("I am panert,pid:%d,ppid:%d,cnt:%d\n",getpid(),getppid(),cnt);
  //    cnt--;
  //    sleep(1);

  //  }
  //  pid_t ret = wait(NULL);
  //  if(ret == id)
  //  {
  //    printf("wait suceess,ret:%d\n",ret);
  //  }
  //}


//  return 0;
//}




void RunChild()
{
  int cnt = 5;
  while(cnt)
  {
    printf("I am child process,pid:%d,ppid:%d\n",getpid(),getppid());
    sleep(1);
    cnt--;
  }
}

int main()
{
  for(int i =0; i < N; i++)
  {
    pid_t id = fork(); 
    if(id == 0)
    {
      RunChild();
      exit(0);
    }
    printf("create child process:%d success\n",id);

  }
  sleep(10);

  for(int i = 0; i < N; i++)
  {
    pid_t id = wait(NULL);
    if(id > 0)
    {
      printf("wait:%d success\n",id);
    }
  }




  return 0;
}







