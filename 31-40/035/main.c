#include <stdio.h>

/* Проверяем может ли число быть выражением в виде суммы простых чисел */
int checkPrime(int n);

int main(void)
{
    int n, i, flag = 0;

    printf("Введите целое положительное число: ");
    scanf("%d", &n);

    for (i = 2; i <= n / 2; ++i) {
        /* Проверяем является ли i простым */
        if (checkPrime(i) == 1) {
            /* Проверяем является ли i простым */
            if (checkPrime(n - i) == 1)
                printf("%d = %d + %d\n", n, i, n - i); /* n = primeNumber1 + primeNumber2 */
        }
    }

    if (flag == 0)
        printf("%d не может быть выражено как сумма простых чисел.", n);

    printf("\n");

    return 0;
}

/* Функция проверки простого числа */
int checkPrime(int n)
{
    int i, isPrime = 1;

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            isPrime= 0;
            break;
        }
    }

    return isPrime;
}