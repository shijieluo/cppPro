/*system V共享内存*/
/*

       #include <sys/ipc.h>
       #include <sys/shm.h>

       int shmget(key_t key, size_t size, int shmflg);
       创建共享内存
       void *shmat(int shmid, const void *shmaddr, int shmflg);

       int shmdt(const void *shmaddr);
       
*/
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main(){
    void *shm = NULL;
    int shmid = shmget(1234, 4096, 0666|IPC_CREAT);
    if(shmid < 0){
        cout << "create shared memory failed..." << endl;
        exit(1);
    }
    shm = shmat(shmid, 0, 0);
    char s[] = "this is shmWriter..";
    strncpy(static_cast<char*>(shm), s, sizeof(s));
    if(shmdt(shm)){
        cout << "shm detaches failed..." << endl;
    }
    return 0;    
}