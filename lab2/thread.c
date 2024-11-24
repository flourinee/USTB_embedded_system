#include<pthread.h>
#include<stdio.h>
int g_Flag;
void* thread1(pthread_t* pid){
    g_Flag=1;
    printf("This is thread 1,the g_Flag is%d\n",g_Flag);
    pthread_join(*pid,NULL);
    printf("Quiting thread1......\n");
}
void* thread2(){
    g_Flag=2;
    printf("This is thread 2,the g_Flag is%d\n",g_Flag);
    printf("Quiting thread2......\n");
}
int main(){
    pthread_t th1,th2;
    printf("The orginal value of g_Flag is:%d\n",g_Flag);
    pthread_create(&th1,NULL,(void*)thread1,&th2);
    pthread_create(&th2,NULL,(void*)thread2,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    return 0;
}