//17114076
//Vishal Garg
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#define MAX 80 //define msg/buffer size
#define PORT 8080 //just a porrt no. rest its your choice choose whatever you want to
#define SAi struct sockaddr_in
#define blog 5
int main(int argc,char const *argv[])
{
    int node1_fd, new_socket, msg;
    SAi address;
    int opt = 1;
    int addrlen=sizeof(address);
    char buffer[MAX]={0};
    char *hola="Hola by node1";

    //Creates socket file descriptor
    if((node1_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) //creates socket AF_NET signifies IPV4,STREAM refers to TCP, and ) for IP
    {
        perror("unable to create socket");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT );
    if (bind(node1_fd, (struct sockaddr *)&address, sizeof(address))<0) //binds to the address and port number specified
    { 
        perror("binding failure"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(node1_fd, blog) < 0) //makes node1 to listen
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(node1_fd, (struct sockaddr *)&address, //extracts first connection req on the queue of pending connections and creates a new connected socket
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    msg = read( new_socket , buffer, MAX); 
    printf("%s\n",buffer ); 
    send(new_socket , hola , strlen(hola) , 0 );
    printf("Hello message sent\n"); 
    return 0; 
} 