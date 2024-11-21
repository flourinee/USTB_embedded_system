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
    char buf[65535];
    memset(buf,0,sizeof(buf));
    int file=open(path,O_RDONLY);
    read(file,buf,1000);
    int shmid=shmget(IPC_PRIVATE,sizeof(buf),0666|IPC_CREAT);
    pid_t pid;
    pid=fork();
    if(pid==0){
        printf("this is the sub process!\n");
        void* shmaddr=shmat(shmid,0,0);
        int file;
        file=open("./readme.txt",O_RDONLY);
        char buf_r[1000];
        read(file,buf_r,sizeof(buf_r));
        strcpy(shmaddr,buf_r);
        shmdt(shmaddr);
        exit(0);
    }else{
        sleep(3);
        printf("this is the main process!\n");
        void* shmaddr=shmat(shmid,0,SHM_RDONLY);
        int file;
        file=open("./writeme.txt",O_WRONLY);
        write(file,shmaddr,100);
        shmdt(shmaddr);
    }
    return 0;
}