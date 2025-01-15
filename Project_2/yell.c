#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = 1;
    if (argc == 1){
        while (1 == 1){
            char terminal_text[2048];
            int size = read(0, terminal_text, 2048);
            if (size == 0){
                break;
            }
            for (int i = 0; i < size; i++){
                char upper_char = toupper(terminal_text[i]);
                write(1, &upper_char, 1);
            
            }
        }
    }


    else {

        while (i <= argc){
            char *file_name = argv[i];
            int file_des = open(file_name, O_RDONLY);
            char file_txt[2048];
            int size = read(file_des, file_txt, 2048);
            for (int i = 0; i < size; i++){
                char upper_char = toupper(file_txt[i]);
                write(1, &upper_char, 1);
            }
            close(file_des);
            i++;
        }
    }
}
