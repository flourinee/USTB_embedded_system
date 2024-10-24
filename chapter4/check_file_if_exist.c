#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char* argv[]){
    char buf[20];
    if(argc==1) {
        printf("please key in the file path!\n");
        return -1;
    }
    int file=open(argv[1],O_RDONLY);
    if(file<0){
        printf("file does not exit!\n");
        return -1;
    }else{
        printf("file exists");
    }
    return 0;
}