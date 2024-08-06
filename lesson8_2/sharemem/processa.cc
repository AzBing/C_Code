#include "comm.hpp"

extern Log log;

int main()
{
    int shmid = GetShm();
    char *shmaddr = (char*)shmat(shmid, nullptr, 0);

    while(true)
    {
        cout << "Please Enter@ ";
        fgets(shmaddr, 4096, stdin);

    }

    shmdt(shmaddr);
    return 0;
}