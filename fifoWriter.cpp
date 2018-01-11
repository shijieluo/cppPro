/*本程序从一个文件中读取数据后写入命名管道*/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
using namespace std;
int main(){
    const char *fifo_name = "/home/luoshijie/lsj/myfifo";
    const char *file_name = "/home/luoshijie/lsj/myfile.txt";
    if(access(fifo_name,F_OK)<0){
        //fifo文件不存在,需要创建.
        if(mkfifo(fifo_name, 0755) < 0){
            cout << "create fifo failed" << endl;
        }
    }
    int fifo_fd, file_fd, n;
    fifo_fd = open(fifo_name, O_WRONLY);
    file_fd = open(file_name, O_RDONLY);
    if(fifo_fd < 0){
        cout << "open fifo_fd failed" << endl;
    }
    if(file_fd < 0){
        cout << "open file_fd failed" << endl;
    }
    char buffer[PIPE_BUF+1];
    memset(buffer, 0, sizeof(buffer));
    while((n=read(file_fd, buffer, PIPE_BUF))>0){
        write(fifo_fd, buffer, n);
    }
    close(fifo_fd);
    close(file_fd);
}