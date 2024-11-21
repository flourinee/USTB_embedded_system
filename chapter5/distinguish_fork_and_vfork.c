#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<sys/types.h>
int main(){
    pid_t pid1,pid2;
    int cnt=0;
    printf("this part is created by fork\n");
    pid1=fork();
    cnt++;
    if(pid1<0) printf("can not fork process\n");
    else if(pid1>0) printf("this is parent process,pid is %d,data is %d\n",getpid(),cnt);
    else {
        pid1=fork();
        printf("this is children process,pid is %d,data is %d\n",getpid(),cnt);
    } 
     return 0;
}