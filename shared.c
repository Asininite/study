#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define SIZE 1024


int main() {

    // Writer process
    key_t key = ftok("file", 0);
    int shmid = shmget(key, SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    sprintf(shmaddr, "This is the message in shared memory");

    // Reader process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        printf("Reader is reading from shared memory...\n");
        printf("Message from shared memory: %s\n", shmaddr);
        
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
    } 
    else {
        printf("Writer is writing to shared memory...\n");
        printf("Writer process completed.\n");
        wait(NULL);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

}