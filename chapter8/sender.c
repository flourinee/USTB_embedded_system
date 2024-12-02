#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<unistd.h>  
#define port 37211
#define max_buf_size 65535 
  
int main() {  
    int sockfd,n,rec_len;  
    char recvline[max_buf_size], sendline[max_buf_size];  
    char buf[]="hello ,this is a tcp/ip test program!";  
    char ip4[]="127.0.0.1";
    struct sockaddr_in servaddr;  
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){  
    printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);  
    exit(0);  
    }  
  
    memset(&servaddr,0,sizeof(servaddr));  
    servaddr.sin_family=AF_INET;  
    servaddr.sin_port=htons(port);  
    if(inet_pton(AF_INET,ip4,&servaddr.sin_addr)<=0){  
    printf("inet_pton error for %s\n",ip4);  
    exit(0);  
    }  
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){  
    printf("connect error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
    if(send(sockfd,buf,strlen(buf),0)<0){  
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);  
        exit(0);  
    }  
    if((rec_len=recv(sockfd,buf,max_buf_size,0)) == -1){  
       perror("recv error");  
       exit(1);  
    }  
    close(sockfd);  
    exit(0);  
}  