#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/sem.h>

int sem_v(int sid)
{
	struct sembuf sem_lock = { 0, -1, IPC_NOWAIT };
	semop(sid,&sem_lock,1);
	printf("using sem...\n");
}

int sem_p(int sid)
{
	struct sembuf sem_unlock = { 0, 1, IPC_NOWAIT };
	semop(sid,&sem_unlock,1);
	printf("release sem...\n");
}

int main()
{
    int shmid,sid;
	key_t key;
	key=ftok(".",1234);
	
    if ((shmid = shmget(1234, 1024, 0666|IPC_CREAT)) == -1) 
    {
        printf("creat shm error\n");
        exit(1);
    }
    char *addr;
    addr=shmat(shmid,0,0);

	sid=semget(key,1,0666|IPC_CREAT);

    char buf[1024];
	sem_v(sid);
    strcpy(buf, addr);
    sem_p(sid);
    printf("read already: %s\n", buf);
    
    shmdt(addr);
    
    // 删除共享内存
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}