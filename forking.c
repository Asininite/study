#define _XOPEN_SOURCE 700
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t p = fork();

    if(p<0){
        printf("fork failed");
        exit(1);
    }
    else if(p==0){
        printf("returned to child process %d",getpid());
    }
    else{
        printf("returned to parent process %d,",p);
    }

    return 0;
}

