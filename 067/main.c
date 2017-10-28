//
// Created by Oleg Bukatchuk on 28/10/2017.
//

// Отображение исходного кода программы
#include <stdio.h>

int main(void) {

    FILE *fp;
    char c;
    fp=fopen(__FILE__,"r");

    do {

        c=getc(fp);
        putchar(c);

    } while (c!=EOF);

    fclose(fp);

    return 0;

}