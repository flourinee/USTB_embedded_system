#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
    char ch=0;
    FILE* fp;
    fp=fopen("./iowrite.txt","wt+");
    while (ch!='\n') {
        scanf("%c",&ch);
        fputc(ch,fp);
    }  
    fclose(fp); 
    return 0;
}