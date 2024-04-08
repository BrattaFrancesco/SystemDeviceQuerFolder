#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sign_handler(int sig);

int last_last, last, current;
int n = 0;

void sign_handler(int sig){
    n++;
    last_last = last;
    last = current;

    if (sig==SIGUSR1)
        current = 1;
    else if (sig==SIGUSR2)
        current = 2;

    if(n == 1){
        return;
    }

    if(current == last && last == last_last) {
        fprintf(stdout, "Stop...\n");
        exit(1);
    } else if(current == last) {
        fprintf(stdout, "error...\n");
    } else if (current != last) {
        fprintf(stdout, "success...\n");
    }

    return;
}

int main() {
    if (signal(SIGUSR1, sign_handler) == SIG_ERR) {
        fprintf (stderr, "Signal Handler Error.\n");
    return (1);
  }
  if (signal(SIGUSR2, sign_handler) == SIG_ERR) {
        fprintf (stderr, "Signal Handler Error.\n");
    return (1);
  }

  while (1) {
    //fprintf (stdout, "Before pause.\n");
    pause ();
    //fprintf (stdout, "After pause.\n");
  }

  return (0);
}