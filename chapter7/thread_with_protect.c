#include<pthread.h>
#include<stdio.h>
int cnt;
void clean(void* arg){
    printf("I am cleaning a error thread with the arg %s:!\n",arg);
}
void* protect(){
    char str[]="this is an arg!";
    printf("I am creating a thread with protect method.\n");
    pthread_cleanup_push(clean,str);
    if(cnt==1) pthread_exit(0);
    pthread_cleanup_pop(0);
}
int main(){
    pthread_t tid;
    printf("please select whether use pthread_exit,1 for use\n");
    scanf("%d",&cnt);
    pthread_create(&tid,NULL,(void*)protect,NULL);
    pthread_join(tid,NULL);
    return 0;
}