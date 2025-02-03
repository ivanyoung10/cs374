#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pfd[2];
    char *file = "./lswc";

    if (argc > 1) {
        file = argv[1];
    }

    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { 
        close(pfd[1]); 

        if (dup2(pfd[0], 0) == -1) {
            perror("dup2 in child");
            exit(1);
        }
        close(pfd[0]); 

        execlp("wc", "wc", "-l", NULL); 
        perror("execlp wc");
        exit(1);
    } else { 
        close(pfd[0]); 

        if (dup2(pfd[1], 1) == -1) {
            perror("dup2 in parent");
            exit(1);
        }
        close(pfd[1]);

        execlp("ls", "ls", "-1a", file, NULL);
        wait(NULL);
        perror("execlp ls");
        exit(1);
    }
}