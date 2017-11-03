#include <stdio.h>
#include <stdlib.h>

/* Вычисляем количество итераций цикла */
int main(void)
{
    int k = 0, i = 0;

    while (k < 7) {
        k = 1 + rand() % 10;
        i++;
    }

    printf("Количество итераций %d\n", i);

    return 0;
}