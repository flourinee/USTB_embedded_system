#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid=vfork();
    if(pid<0) printf("can not fork process\n");
    else if(pid==0) printf("this is chidren process,pid is %d\n",getpid());
    else printf("this is parent process,pid is %d\n",getpid());
    return 0;
}