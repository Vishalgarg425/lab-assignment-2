//17114076
//Vishal Garg
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#define MAX 80 //define msg/buffer size
#define PORT 8080 //just a porrt no. rest its your choice choose whatever you want to
#define SAi struct sockaddr_in

int main(int argc,char const *argv[])
{
    int node2_fd, msg;
    SAi s_address;
    char buffer[MAX]={0};
    char *hola="Hola by node2";

    //Creates socket file descriptor
    if((node2_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) //creates socket AF_NET signifies IPV4,STREAM refers to TCP, and 0 for IP
    {
        perror("unable to create socket");
        return -1;
    }
    s_address.sin_family=AF_INET;
    s_address.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &s_address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    }  
    if (connect(node2_fd, (struct sockaddr *)&s_address, sizeof(s_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    send(node2_fd , hola , strlen(hola) , 0 );
    printf("Hello message sent\n"); 
    msg = read( node2_fd , buffer, MAX); 
    printf("%s\n",buffer ); 
    return 0; 
} 