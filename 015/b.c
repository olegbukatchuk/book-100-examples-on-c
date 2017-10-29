#include <stdio.h>

/* Определяем является ли число положительным или отрицательным */
int main(void)
{
    double number;

    printf("Введите число: ");
    scanf("%lf", &number);

    if (number < 0.0)
        printf("Отрицательное.\n");
    else if (number > 0.0)
        /* true если number > 0 */
        printf("Положительное.\n");
    else
        /* иначе */
        printf("Вы ввели 0.\n");

    return 0;
}
