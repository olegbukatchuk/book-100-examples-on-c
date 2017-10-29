#include <stdio.h>

/* Вычисление факториала с использованием рекурсии */
long int fact(int n);

int main(void)
{
    int n;

    printf("Введите положительное число: ");
    scanf("%d", &n);
    printf("Факториал %d = %ld\n", n, fact(n));

    return 0;
}

long int fact(int n) {
    if (n >= 1)
        return n*fact(n-1);
    else
        return 1;
}
