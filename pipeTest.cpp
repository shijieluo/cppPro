#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000
using namespace std;
int main(){
    int fd[2];
    if(pipe(fd) < 0){
        cout << "create pipe failed" << endl;
    }
    pid_t pid = fork();
    if(pid < 0){
        cout << "fork failed" << endl;
    }else if(pid == 0){
        //child process
        close(fd[0]);
        char buffer[MAXSIZE];
        memset(buffer, 0, sizeof(buffer));
        memcpy(buffer, "i am child\n", 11);
        for(int i = 0; i < 2; i++){
            write(fd[1],buffer,MAXSIZE);
            cout<<"child sent message:"<<buffer<<endl;
            sleep(2);
            }
    }else{
        //father process
        sleep(8);
        close(fd[1]);
        char recvbuffer[MAXSIZE];
        memset(recvbuffer, 0, sizeof(recvbuffer));
        for(int j = 0; j < 2; j++){
            read(fd[0],recvbuffer,sizeof(recvbuffer));
            cout<<"father recv message:"<<recvbuffer<<endl;
        }
        
    }
    
}