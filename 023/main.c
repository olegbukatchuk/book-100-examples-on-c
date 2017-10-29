#include <stdio.h>

/* Определяем количество цифр в целом числе */
int main(void)
{
    long long n;
    int count = 0;

    printf("Введите целое число: ");
    scanf("%lld", &n);

    while (n != 0) {
        n /= 10;
        ++count;
    }

    printf("Количество цифр: %d\n", count);

    return 0;
}