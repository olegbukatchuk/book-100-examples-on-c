#include <stdio.h>

#define TRUE  0
#define FALSE 1

/* Бинарный (двоичный) поиск в целочисленном массиве */
int main(void)
{
    int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int left = 0;
    int right = 10;
    int middle = 0;
    int number = 0;
    int bsearch = FALSE;
    int i = 0;

    printf("Массив: ");

    for (i = 0; i < 10; i++)
        printf("[%d] ", array[i]);

    printf("\nВведите искомый элемент: ");
    scanf("%d", &number);

    while (bsearch == FALSE && left <= right) {
        middle = (left + right) / 2;

        if (number == array[middle]) {
            bsearch = TRUE;

            printf("** Число есть в массиве! **\n");
        } else {
            if (number < array[middle])
                right = middle - 1;
            if (number > array[middle])
                left = middle + 1;
        }
    }

    if (bsearch == FALSE)
        printf("-- Элемент не найден! --\n");
    return 0;
}