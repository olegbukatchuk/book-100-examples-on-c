#include <stdio.h>

/* Вычисление степени числа без функции pow() */
int main(void)
{
    int base, exponent;

    long long result = 1;

    printf("Введите число: ");
    scanf("%d", &base);

    printf("Введите степень: ");
    scanf("%d", &exponent);

    while (exponent != 0) {
        result *= base;
        --exponent;
    }

    printf("Результат = %lld\n", result);

    return 0;
}
