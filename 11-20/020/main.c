#include <stdio.h>

/* Вычисление последовательности Фибоначчи */
int main(void)
{
    int i, n, t1 = 0, t2 = 1, nextTerm = 0;

    printf("Введите количество элементов последовательности: ");
    scanf("%d", &n);

    printf("Последовательность Фибоначчи: ");

    for (i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d, ", t1);
            continue;
        }

        if (i == 2) {
            printf("%d, ", t2);
            continue;
        }

        nextTerm = t1 + t2;

        t1 = t2;
        t2 = nextTerm;

        printf("%d, ", nextTerm);
    }

    printf("\n");

    return 0;
}