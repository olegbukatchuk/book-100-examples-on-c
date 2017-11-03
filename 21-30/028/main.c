#include <stdio.h>

/* Выводим простые числа между a и b (между low и high) */
int main(void)
{
    int low, high, i, flag;

    printf("Выводим простые числа между a и b, введите a и b: ");
    scanf("%d %d", &low, &high);

    while (low < high) {

        flag = 0;

        for (i = 2; i <= low / 2; ++i) {
            if (low % i == 0) {
                flag=1;
                break;
            }
        }

        if (flag == 0)
            printf("%d \n",low);

        ++low;
    }

    return 0;
}