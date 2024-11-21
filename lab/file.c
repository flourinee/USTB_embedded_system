#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char* argv[]){
    char buf[100];
    int src=open(argv[1],O_RDONLY);
    int dest=open(argv[2],O_WRONLY);
    read(src,buf,100);
    printf("%s",buf);
    write(dest,buf,100);
    return 0;
}