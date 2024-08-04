#include "comm.hpp"

using namespace std;
int main()
{
    // 创建
    int n = mkfifo(FIFO_FIFE, 0664);
    if (n == -1)
    {
        perror("mkfifo");
        exit(FIFO_CREATE_ERR);
    }
    // 打开
    int fd = open(FIFO_FIFE,O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(FIFO_OPEN_ERR);
    }

    while(true)
    {
        char buffer[1024] = {0};
        int x = read(fd, buffer, sizeof(buffer));
        if(x > 0)
        {
            buffer[x] = 0;
            cout << "client say# " << buffer << endl;
        }
    }


    close(fd);

    int m = unlink(FIFO_FIFE);
    if(m == -1)
    {
        perror("unlink");
        exit(FIFO_DELETE_ERR);
    }


    return 0;
}
