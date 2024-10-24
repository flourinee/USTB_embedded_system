#include<stdio.h>
#include<string.h>
#define maxn 10000
int n;
int data[maxn];
int to_num(char* s){
    int tmp=0;
    for(int i=0;i<strlen(s);i++){
        tmp=tmp*10+s[i]-48;
    }
    return tmp;
}
void bubble(int dat[],int size){
    for(int i=1;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(dat[i]>dat[j]){
                int tmp=dat[j];
                dat[j]=dat[i];
                dat[i]=tmp;
            }
        }
    }
    for(int i=1;i<size;i++){
        printf("%d ",dat[i]);
    }  
    printf("\n");  
}
int main(int argc ,char* argv[]){
    for(int i=1;i<argc;i++){
        data[i]=to_num(argv[i]);
    }
    bubble(data,argc);
    return 0;
}
