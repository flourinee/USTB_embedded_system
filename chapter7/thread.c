#include<pthread.h>
#include<stdio.h>
struct data{
    int num;
    char ch;
    char zero[3];
};
void* thread_proc(struct data* d){
    printf("The num you keyed in is:%d\n",d->num);
    printf("The char you keyed in is:%c\n",d->ch);
}
int main(){
    pthread_t tid;
    struct data dat;
    printf("please scanf a number and a character in order\n");
    scanf("%d %c",&dat.num,&dat.ch);
    pthread_create(&tid,NULL,(void*)thread_proc,&dat);
    pthread_join(tid,NULL);
    return 0;
}