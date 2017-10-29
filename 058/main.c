#include <stdio.h>

/* Копирование строки без strcpy() */
int main()
{
    char s1[100], s2[100], i, j;

    printf("Введите строку s1: ");
    gets(s1);

    for (i = 0; s1[i] != '\0'; ++i)
        s2[i]=s1[i];

    s2[i]='\0';
    printf("Строка s2: %s\n", s2);

    return 0;
}