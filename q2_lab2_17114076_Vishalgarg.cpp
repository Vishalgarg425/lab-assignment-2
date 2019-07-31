//C program to demonstrate orphan process
//17114076
//Vishal Garg
#include <bits/stdc++.h>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() {
	if (fork() != 0) {//call fork to get a child
        sleep(2);
        printf("PARENT [%d] is going to die[%d]\n",getpid(),getppid());//teminates before child rendering it orphan
	} 
    else {
    sleep(1);
    printf("CHILD [%d] having original parent,[%d]\n",getpid(),getppid());
    sleep(3);//orphan process gets adopted by init/systemd process
    printf("CHILD [%d] having original parent,[%d]\n",getpid(),getppid());
	} 
    return 0;   
}