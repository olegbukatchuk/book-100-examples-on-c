#include <stdio.h>

/* Демонстрация цикла do...while() */
int main(void)
{
    int n, i, sum = 0;

    do {
        printf("Введите целое положительное число > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1; i <= n; ++i)
        sum+=i;

    printf("Сумма = %d\n", sum);

    return 0;
}