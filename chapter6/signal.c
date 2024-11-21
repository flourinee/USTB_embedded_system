#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
void signal_process(int signal){
    printf("Now the system captured the signal sigtsop\n");
    exit(0);
}
int main(){
    signal(SIGSTOP,signal_process);
    printf("Now the system will send the signal sigstop\n"); 
    pause();
   
}