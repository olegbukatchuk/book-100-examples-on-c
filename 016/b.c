#include <stdio.h>

/* Сумма натуральных чисел с помощью цикла while() */
int main(void)
{
    int n, i, sum = 0;

    printf("Введите n: ");
    scanf("%d", &n);

    i = 1;

    while (i <= n) {
        sum += i;
        ++i;
    }

    printf("Сумма = %d\n", sum);

    return 0;
}
