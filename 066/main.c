// Чтение строки из файла
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char c[1000];
    FILE *fptr;

    if ((fptr=fopen("text.txt","r"))==NULL) {

        printf("Ошибка при открытии файла");

        // Код возврата 1 - произошла ошибка
        exit(1);

    }

    // Читаем до символа \n
    fscanf(fptr,"%[^\n]",c);

    printf("Прочитано из файла:\n%s\n",c);

    // Закрываем файл
    fclose(fptr);

    return 0;

}