#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>
#include<unistd.h>  
#include<netinet/in.h>
#include<pthread.h>  
#define DEFAULT_PORT 37211  
#define max_buf_size 65535 
#define max_connect_capacity 128
int maxid=1;
int connect_fd[max_connect_capacity];
int socket_fd;
struct thread_arg{
    int id;
};
void creat_listening_thread(struct thread_arg* info){
    int realsize=0,i=0;
    char buff[max_buf_size];
    char idinfo[]="Hello user!"; 
    while (1){
        memset(buff,0,sizeof(buff));
        connect_fd[info->id]=accept(socket_fd,(struct sockaddr*)NULL,NULL);
        send(connect_fd[info->id],idinfo,sizeof(idinfo),0);
        realsize=recv(connect_fd[info->id],buff,max_buf_size,0);
        printf("msg from client: %s\n", buff);
        if(realsize>0) {        
            if(send(connect_fd[info->id],buff,realsize,0) == -1) perror("send error"); 
        }
    }  
    return ;
}

int main(){  
    int i;
    int wind=maxid;
    pthread_t tid[max_connect_capacity];
    struct sockaddr_in servaddr; 
    struct thread_arg th[max_connect_capacity]; 
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0))==-1){  
    	printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }   
    memset(&servaddr,0,sizeof(servaddr)); 
    memset(&th,0,sizeof(th));   
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(DEFAULT_PORT);
    if(bind(socket_fd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){  
    	printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }  
    if(listen(socket_fd,max_connect_capacity)==-1){  
    	printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }  
    printf("waiting for client's request\n");  
    while(1){  
        if(maxid==wind){
            wind*=10;
            for(i=maxid;i<=wind;i++){
                th[i].id=i;
                pthread_create(&tid[i],NULL,(void*)creat_listening_thread,&th[i]);
            }
        }
    }       
    close(socket_fd);  
}  