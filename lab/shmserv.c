#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<string.h>


int main(){
    char path[]="./readme.txt";
    char buf_r[88];
    memset(buf_r,0,sizeof(buf_r));
    int file=open(path,O_RDONLY);
    read(file,buf_r,1000);
    int shmid=shmget((key_t)1952,sizeof(buf_r),0666|IPC_CREAT);
    void* shmaddr=shmat(shmid,0,0);
    strcpy(shmaddr,buf_r);
    printf("%s",shmaddr);
    shmdt(shmaddr);
    return 0;
}