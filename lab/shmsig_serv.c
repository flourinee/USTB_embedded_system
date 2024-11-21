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

int init_sem(int sem_id, int sem_value)
{
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
    } arg;
    arg.val = sem_value;
}

int main()
{
    int shmid,sid;
    if ((shmid = shmget(1234, 1024, 0666|IPC_CREAT)) == -1) 
    {
        printf("creat shm error\n");
        exit(1);
    }
    char *addr;
    addr=shmat(shmid,0,0);

    char buf[] = "this is sem exercise!";

	key_t sem_key;
	sem_key=ftok(".", 1234);
	sid=semget(sem_key,1,0666|IPC_CREAT);
	init_sem(sid,1);
	sem_v(sid);
		
    strcpy(addr, buf);
    
    printf("already: %s\n", addr);
	sem_p(sid);
    shmdt(addr);
    
    return 0;
}