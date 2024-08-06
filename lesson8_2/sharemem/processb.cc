#include "comm.hpp"

extern Log log;

int main()
{
    int shmid = CreateShm();    
    char *shmaddr = (char*)shmat(shmid, nullptr, 0);

    struct shmid_ds shmds;
    while(true)
    {
        char c;
        cout << "client say@ " << shmaddr << endl; //直接访问共享内存
        sleep(1);
        shmctl(shmid, IPC_STAT, &shmds);
        
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, nullptr);
    return 0;
}