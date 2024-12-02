#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>
#include<unistd.h>  
#include<netinet/in.h>  
#define DEFAULT_PORT 37211  
#define max_buf_size 65535 
int main(){  
    int	socket_fd,connect_fd;  
    struct sockaddr_in servaddr;  
    char buff[max_buf_size];  
    memset(buff,0,max_buf_size);
    int realsize;  
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0))==-1){  
    	printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }   
    memset(&servaddr,0,sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(DEFAULT_PORT);
    if(bind(socket_fd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){  
    	printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }  
    if(listen(socket_fd,10)==-1){  
    	printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
    	exit(0);  
    }  
    printf("waiting for client's request\n");  
    while(1){  
        memset(buff,0,max_buf_size);
        if((connect_fd=accept(socket_fd,(struct sockaddr*)NULL,NULL)) == -1){  
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
        continue;  
    }  
    realsize = recv(connect_fd,buff,max_buf_size,0);   
    char ans[max_buf_size]="the message you sent is:";
    strcat(ans,buff);
    if(send(connect_fd,ans,25+realsize,0) == -1) perror("send error");    
    printf("msg from client: %s\n", buff);  
    close(connect_fd);  
    }  
    close(socket_fd);  
}  