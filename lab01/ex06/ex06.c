#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char** argv) {
    int h = atoi(argv[1]);
    int n = atoi(argv[2]);
    int pid;

    printf("Generatig a process tree of heigh: %d and degree: %d\n", h, n);
    printf("\tMain process PID: %d\n", getpid());

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            pid = fork();
            if(pid == 0){
                break;
            }else{
                printf("\t\tPID %d is generating PID %d\n", getpid(), pid);
            }
            if(j==n-1){
                printf("\t\t\tExiting with PID: %d\n", getpid());
                exit(0);
            }
        }
    }

    printf("\tLeaf process PID: %d\n", getpid());
}