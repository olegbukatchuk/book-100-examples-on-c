#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 10

void quicksort(int arr[], int low, int high);

int main(void)
{
    int array[MAXARRAY] = {0};
    int i = 0;

    /* Загружаем в массив случайные числа */
    for (i = 0; i < MAXARRAY; i++)
        array[i] = rand() % 100;

    printf("До сортировки: ");

    for (i = 0; i < MAXARRAY; i++)
        printf(" %d", array[i]);

    printf("\n");

    quicksort(array, 0, (MAXARRAY - 1));

    printf("После сортировки: ");

    for (i = 0; i < MAXARRAY; i++)
        printf(" %d ", array[i]);

    printf("\n");

    return 0;
}

/* Сортируем все между 'low' <-> 'high' */
void quicksort(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int y = 0;

    /* Опорный элемент */
    int z = arr[(low + high) / 2];

    /* Разделение */
    do {
        /* Находим элемент левее */
        while (arr[i] < z) i++;

        /* Находим элемент правее */
        while (arr[j] > z) j--;

        if (i <= j) {
            /* Меняем местами 2 элемента */
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++;
            j--;
        }

    } while (i <= j);

    if (low < j)
        quicksort(arr, low, j);

    if (i < high)
        quicksort(arr, i, high);
}