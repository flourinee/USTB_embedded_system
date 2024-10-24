#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char* argv[]){
    char buf[]="Hello,welcome to Beijing!";
    if(argc==1) {
        printf("please key in the file path!\n");
        return -1;
    }
    int file=open(argv[1],O_WRONLY);
    if(file<0){
        printf("read failed!\n");
        return -1;
    }else{
        int op=write(file,buf,sizeof(buf));
        if(op==-1) {
            printf("Write file failed!");
            return -1;
        }else{
            printf("write file sucess!");
        }
    }
    return 0;
}