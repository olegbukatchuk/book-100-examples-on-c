#include <stdio.h>

/* Определяем является ли число положительным или отрицательным */
int main(void)
{
    double number;

    printf("Введите число: ");
    scanf("%lf", &number);

    if (number <= 0.0) {
        if (number == 0.0)
            printf("Вы ввели 0.\n");
        else
            printf("Отрицательное.\n");
    } else
        printf("Положительное.\n");

    return 0;
}
