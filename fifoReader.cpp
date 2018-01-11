/*读取命名管道中的信息*/
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
using namespace std;
int main(){
    const char* fifo_name="/home/luoshijie/lsj/myfifo";
    int mkfifo_fd;
    mkfifo_fd = open(fifo_name, O_RDONLY);
    char buffer[PIPE_BUF+1];
    memset(buffer, 0, sizeof(buffer));
    while(read(mkfifo_fd, buffer, PIPE_BUF)){
        cout<<"buffer:"<<buffer<<endl;
    }
    close(mkfifo_fd);
}
