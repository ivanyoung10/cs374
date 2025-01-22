#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    while(1) {
        char line[1024];
        printf("mush> ");
        fflush(stdout);

        fgets(line, sizeof(line), stdin);


        char *token;
        char *tokens[128] = {0};

        if ((token = strtok(line, " \n")) != NULL){
            tokens[0] = token;
        }
    
        int token_num = 0;
        while ((token = strtok(NULL, " \n")) != NULL) {
            token_num += 1;
            tokens[token_num] = token;
        }

        char *cd = "cd";
        char *exit_ptr = "exit";

        if (tokens[0] == NULL){
            continue;
        }
        else if (strcmp(tokens[0], cd) == 0){
            int status = chdir(tokens[1]);
            if (status == -1){
                perror("Error");
            }
        }
        else if (strcmp(tokens[0], exit_ptr) == 0) {
            exit(0);
        }
        else {
            pid_t parent_pid = getpid();
            fork();

            if (parent_pid == getpid()){
                wait(NULL);
            }
            else {
                if (execvp(tokens[0], tokens)){
                    perror("Error");
                    exit(1);
                }
            }
        }

       
    }
}

