/*shmReader.cpp*/
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
using namespace std;
int main(){
    void* shm = NULL;
    int shmid;
    shmid = shmget(1234, 4096, 0666 | IPC_CREAT);
    if(shmid < 0){
        cout << "create shared memory failed..." << endl;
        exit(1);
    }
    shm = shmat(shmid, 0, 0);
    cout << static_cast<char*>(shm) << endl;
    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}