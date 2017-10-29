#include <stdio.h>

/* Отображение исходного кода программы */
int main(void)
{
    FILE *fp;
    char c;
    fp = fopen(__FILE__, "r");

    do {
        c=getc(fp);
        putchar(c);
    } while (c != EOF);

    fclose(fp);

    return 0;
}