#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    if (dup2(fd, 1) < 0){
        perror("dup2");
        exit(1);
    }
    close(fd);

    char *command = argv[2];
    argv = argv + 2;
    execvp(command, argv);

    perror("execvp");
    exit(1);
}