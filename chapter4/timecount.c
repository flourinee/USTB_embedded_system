#include<stdio.h>
#include<sys/time.h>
int main(){
    struct timeval start,end;
    double cnt=0;
    gettimeofday(&start,0);
    for(int i=0;i<10000;i++){
        asm("NOP");
    }
    gettimeofday(&end,0);
    cnt=(end.tv_sec-start.tv_sec)*1.0+1.0*(end.tv_usec-start.tv_usec)/1000000;
    printf("Used Time:%lf\n",cnt);
}