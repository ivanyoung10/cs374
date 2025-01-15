#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
    char *file_name = argv[1];
    int file_des = open(file_name, O_RDONLY);
    char file_txt[2048];
    int size = read(file_des, file_txt, 2048);
    write(1, file_txt, size);
    close(file_des);


}