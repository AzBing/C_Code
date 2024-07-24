#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  printf("%s\n",getenv("PATH"));
  printf("%s\n",getenv("HOME"));
  printf("%s\n",getenv("SHELL"));                                             


   // extern char** environ;
   // for(int i = 0; environ[i]; i++)
   // {
   //     printf("%d->%s\n",i, environ[i]);                                         
   // }


 // if(argc != 2)
 // {
 //   printf("Using: %s -[a|h|ah]\n",argv[0]);
 //   return 1;
 // }
 // if(strcmp(argv[1],"-h") == 0)
 // {
 //   printf("hello world!\n");
 // }
 // else if(strcmp(argv[1],"-a") == 0)
 // {
 //   printf("hello linux!\n");
 // }
 // else if(strcmp(argv[1],"-ah") == 0)
 // {
 //   printf("hello world!\n");
 //   printf("hello linux!\n");
 // }
 // else
 // {
 //   printf("hello C++!\n");
 // }

  //  int i = 0;
  //  for(i = 0; i < argc; i++)
  //  {  
  //      printf("argv[%d]:%s\n",i,argv[i]);

  //  }   

    return 0;                                                      
} 
                        
