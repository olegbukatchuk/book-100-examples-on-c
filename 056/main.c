#include <stdio.h>

/* Определение длины строки без функции strlen() */
int main(void)
{
    char s[1000], i;
    printf("Введите строку: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; ++i);

    printf("Длина строки: %d\n",i);

    return 0;
}