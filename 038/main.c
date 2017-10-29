#include <stdio.h>

/* Вычисляем НОД с использованием рекурсии */
int hcf(int n1, int n2);

int main(void)
{
    int n1, n2;

    printf("Введите 2 положительных целых числа: ");
    scanf("%d %d", &n1, &n2);
    printf("НОД = %d\n", hcf(n1, n2));

    return 0;
}

int hcf(int n1, int n2)
{
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}
