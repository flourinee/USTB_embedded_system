#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
    pid_t pid1,pid2;
    int cnt=0;
    printf("now,i will use vfork\n");
    pid1=vfork();
    if(pid1<0) printf("can not fork process\n");
    else if(pid1>0) printf("this is parent process,pid is %d,data is %d\n",getpid(),cnt);
    else {
        pid1=vfork();
        cnt++;
        printf("this is children process,pid is %d,data is %d\n",getpid(),cnt);
        exit(0);
    }   
     return 0;
}