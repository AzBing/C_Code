#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
  pid_t id = fork();
  if(id == 0)
  {
    printf("before:I am a process,pid:%d,ppid:%d\n",getpid(),getppid());
    sleep(5);
    execl("/usr/bin/ls", "ls", "-a", "-l", NULL);

    exit(0);
  }
  pid_t ret = waitpid(id, NULL, 0);
  if(ret > 0)
  {
    printf("wait success,father pid:%d,ppid:%d,ret:%d\n",getpid(),getppid(),ret);

  }
  sleep(6);



  return 0;
}

