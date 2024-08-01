#include "Mystdio.h"
#include <unistd.h>

#define myfile "test.txt"

int main()
{
    _FILE *fp = _fopen(myfile, "w");
    if(fp == NULL) return 1;

    const char *msg = "i like linux\n";
    int cnt = 1;
    while(cnt){
        _fwrite(fp, msg, strlen(msg));
        // fflush(fp);
        sleep(1);
        cnt--;
    }

    _fclose(fp);

    return 0;
}


