#include <stdio.h>
#include <math.h>

/* Преобразование между двоичной и десятичной системами счисления */
int convertBinaryToDecimal(long long n);
long long convertDecimalToBinary(int n);

int main(void)
{
    long long n;

    printf("Введите двоичное число: ");
    scanf("%lld", &n);
    printf("%lld (двоичное) = %d (десятичное)\n", n, convertBinaryToDecimal(n));

    printf("Введите десятичное число: ");
    scanf("%lld", &n);
    printf("%lld (десятичное) = %d (двоичное)\n", n, convertBinaryToDecimal(n));

    return 0;
}

int convertBinaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    return decimalNumber;
}

long long convertDecimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0) {
        remainder = n % 2;

        printf("Шаг %d: %d/2, Остаток = %d, Частное = %d\n", step++, n, remainder, n / 2);
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    return binaryNumber;
}