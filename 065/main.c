#include <stdio.h>
#include <stdlib.h> /* для функции exit() */

/* Запись предложения в файл */
int main(void)
{
    char sentence[1000];
    FILE *fptr;

    fptr = fopen("text.txt", "w");
    gets(sentence);

    fprintf(fptr, "%s", sentence);

    fclose(fptr);

    return 0;
}