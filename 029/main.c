#include <stdio.h>
#include <math.h>

/* Проверяем является лт число числом Армстронга */
int main(void)
{
    int number, originalNumber, remainder, result = 0, n = 0;

    printf("Введите число: ");
    scanf("%d", &number);

    originalNumber = number;

    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    if (result == number)
        printf("%d - число Армстронга\n", number);
    else
        printf("%d - не является числом Армстронга\n", number);

    return 0;
}