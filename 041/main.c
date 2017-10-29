#include <stdio.h>
#include <math.h>

/* Конвертируем двоичные числа в восьмеричнве и наоборот */
int convertBinaryToOctal(long long binaryNumber);
long long convertOctalToBinary(int octalNumber);

int main(void)
{
    long long binaryNumber;
    int octalNumber;

    printf("Введите двоичное число: ");
    scanf("%lld", &binaryNumber);

    printf("%lld (двоичное) = %d (восьмеричное)\n", binaryNumber, convertBinaryToOctal(binaryNumber));

    printf("Введите восьмеричное число: ");
    scanf("%d", &octalNumber);

    printf("%d (восьмеричное) = %lld (двоичное)\n", octalNumber, convertOctalToBinary(octalNumber));

    return 0;
}

long long convertOctalToBinary(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while (octalNumber != 0) {
        decimalNumber += (octalNumber % 10) * pow(8, i);
        ++i;
        octalNumber /= 10;
    }

    i = 1;

    while (decimalNumber != 0) {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}

int convertBinaryToOctal(long long binaryNumber)
{
    int octalNumber = 0, decimalNumber = 0, i = 0;

    while (binaryNumber != 0) {
        decimalNumber += (binaryNumber % 10) * pow(2, i);
        ++i;
        binaryNumber /= 10;
    }

    i = 1;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}