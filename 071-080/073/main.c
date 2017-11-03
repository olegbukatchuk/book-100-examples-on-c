#include <stdio.h>
#include <string.h>

/* Бинарный поиск по массиву строк */

static int binsearch(char *str[], int max, char *value);

int main(void)
{
    /* Массив должен быть отсортирован */
    char *strings[] = {"audi", "bentley", "bmw", "cadillac", "ford"};

    int i, asize, result;

    i = asize = result = 0;

    asize = sizeof(strings) / sizeof(strings[0]);

    for (i = 0; i < asize; i++)
        printf("%d: %s\n", i, strings[i]);

    printf("\n");

    if ((result = binsearch(strings, asize, "bmw")) != 0)
        printf("'bmw' найдено на позиции: %d\n", result);
    else
        printf("'bmw' не найдено..\n");

    if ((result = binsearch(strings, asize, "mercedes")) != 0)
        printf("'mercedes' найдено на позиции %d\n", result);
    else
        printf("'mercedes' не найдено..\n");

    return 0;
}

static int binsearch(char *str[], int max, char *value)
{
    int position;
    int begin = 0;
    int end = max - 1;
    int cond = 0;

    while (begin <= end) {
        position = (begin + end) / 2;
        if ((cond = strcmp(str[position], value)) == 0)
            return position;
        else if (cond < 0)
            begin = position + 1;
        else
            end = position - 1;
    }

    return 0;
}