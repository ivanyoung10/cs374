#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 1;
    if (argc == 1){
        while (1 == 1){
            char terminal_text[2048];
            int size = read(0, terminal_text, 2048);
            if (size == 0){
                break;
            }
            write(1, terminal_text, size);
            }
    }

    else {

        while (i <= argc){
            char *file_name = argv[i];
            int file_des = open(file_name, O_RDONLY);
            char file_txt[2048];
            int size = read(file_des, file_txt, 2048);
            write(1, file_txt, size);
            close(file_des);
            i++;
        }
    }
}
