#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
int main(){
    int pipe_fd[2];
    pid_t pid;
    char buf[100];
    char s1[]="Writing through pipe!\n";
    char s2[]="Another string,only a test.\n";
    memset(buf,0,sizeof(buf));
    if(pipe(pipe_fd)<0){
        printf("pipe creat error!\n");
        return -1;
    }
    pid=fork();
    if(pid<0){
        printf("can not creat sub process!\n");
        return -2;
    }
    if(pid==0){
        printf("this is sub process,reading:\n");
        close(pipe_fd[1]);
        sleep(1);
        read(pipe_fd[0],buf,100);
        printf("the sub process reads:%s",buf);
        close(pipe_fd[0]);
    }else{
        printf("this is main process,writing:\n"); 
        close(pipe_fd[0]);
        write(pipe_fd[1],s1,sizeof(s1));
        write(pipe_fd[1],s2,sizeof(s2));
        close(pipe_fd[1]);
        sleep(2);
        waitpid(pid,NULL,0);
        exit(0);
    }
    return 0;
}