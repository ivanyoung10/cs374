#include <stdio.h>

int main(){
    int x = 12;
    float y = 3.14;
    char s[] = "Hello, world!\n";

    printf("x is %d, y is %f\n%s", x, y, s);

    int i = 0;
    int mult = 5;

    while (i < 5){
        int value = mult * i;
        printf("%d x 5 = %d\n", i, value);
        i++;
    }

}