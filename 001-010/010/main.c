#include <stdio.h>

/* Является ли число чётным */
int main(void)
{
    int number;

    printf("Введите целое число: ");
    scanf("%d", &number);

    if (number % 2 == 0)
        printf("%d - чётное\n",number);
    else
        printf("%d - нечётное\n",number);

    return 0;
}
