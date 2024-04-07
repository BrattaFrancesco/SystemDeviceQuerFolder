#include <stdio.h>
#include <stdlib.h>

void binary(int *, int, int);

int main (int argc, char *argv[]){
    int n;
    int *vet;

    n = atoi (argv[1]);

    vet = (int *)malloc(n * sizeof(int));
    if (vet == NULL) {
        printf("Allocatin Error.\n");
        exit(1);
    }

    printf("Binary Numbers:\n");
    binary(vet, n, 0);
    free(vet);

    return 0;
}

void binary (int *vet, int n, int i)
{
    int i, j;

    for(i = 0; i <= n; i++){
        if(n == 0){
            //print number
            for (j=0; j<n; j++) {
                printf("%d", vet[j]);
            }
            printf("\n");
            exit(0);
        }else{
            //generate number
            //let's fork two times the father to get 2 children
            if(fork() != 0){
                //Father
                if(fork() != 0){
                    //Father
                    //wait for the children to finish, to avoid zombie children
                    wait((int * ) 0);
                    exit(0);
                }else{
                    //Children2
                    vet[i] = 1;
                }
            }else{
                //Children1
                vet[i] = 0;
            }
        }
    }
    //each children at the end will contiue the loop and be a father itself adding all the possible combination of 0,1 to his vector
    //once reached the lenght of i == n the children got killed and so the father...
    exit(0);
}

/*
if (i >= n) {
    for (j=0; j<n; j++) {
      printf("%d", vet[j]);
    }
    printf("\n");
    return;
  }

  vet[i] = 0;
  binary(vet, n, i+1);

  vet[i] = 1;
  binary(vet, n, i+1);
*/