#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char line[1024];
    printf("prompt> ");
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

   if (execvp(tokens[0], tokens)){
        perror("Error");
   }
   

}