#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char* argv[]){
    if(argc==1) {
        printf("please key in the file path!\n");
        return -1;
    }
    int file=open(argv[1],O_WRONLY);
    if(file<0){
        printf("read failed!\n");
        return -1;
    }else{
        char buf[10];
        printf("please key in 10 characters:\n");
        scanf("%s",buf);
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