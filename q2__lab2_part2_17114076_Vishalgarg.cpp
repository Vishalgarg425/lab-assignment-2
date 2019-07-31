//C program to demonstrate zombie process
//17114076
//Vishal Garg
#include <bits/stdc++.h>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() {
	if (fork() != 0) {//fork to produce a child
        sleep(10);//parent is sleeping hence wont call wait() for child
        printf("PARENT [%d] is terminating now\n",getpid());
	} else {
        sleep(1);
        printf("CHILD [%d] is going to exit but parent [%d] won't wait() it\n",getpid(),getppid());
        exit(0);//child has sent exit but signal hasnt be recieved by parent thus it stays in process table
		} 
     return 0;   
}