#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	pid_t pid = fork();
	if(pid<0){
		printf("can not fork process");
	}else if(pid==0){
		printf("this is children process,pid is %d",getpid());
		_exit(0);
	}
	printf("this is parent process,pid is %d",getpid());
	exit(0);
}

