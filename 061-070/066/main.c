#include <stdio.h>
#include <stdlib.h>

/* Чтение строки из файла */
int main(void)
{
    char c[1000];
    FILE *fptr;

    if ((fptr = fopen("text.txt", "r")) == NULL) {
        printf("Ошибка при открытии файла");
        exit(1); /* Код возврата 1 - произошла ошибка */
    }

    /* Читаем до символа \n */
    fscanf(fptr, "%[^\n]", c);

    printf("Прочитано из файла:\n%s\n", c);

    /* Закрываем файл */
    fclose(fptr);

    return 0;
}