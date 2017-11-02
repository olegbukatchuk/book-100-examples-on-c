#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 10

void mergesort(int a[], int low, int high);

int main(void)
{
    int array[MAXARRAY];
    int i = 0;

    /* Загружаем в массив случайные данные */
    for(i = 0; i < MAXARRAY; i++)
        array[i] = rand() % 100;

    printf("До сортировки: ");

    for (i = 0; i < MAXARRAY; i++)
        printf(" %d", array[i]);

    printf("\n");

    /* Сортировка */
    mergesort(array, 0, MAXARRAY - 1);

    printf("После сортировки: ");

    for (i = 0; i < MAXARRAY; i++)
        printf(" %d", array[i]);

    printf("\n");

    return 0;
}

void mergesort(int a[], int low, int high)
{
    int i = 0;
    int length = high - low + 1;
    int pivot = 0;
    int merge1 = 0;
    int merge2 = 0;
    int working[length];

    if (low == high)
        return;

    pivot = (low + high) / 2;

    mergesort(a, low, pivot);
    mergesort(a, pivot + 1, high);

    for (i = 0; i < length; i++)
        working[i] = a[low + i];

    merge1 = 0;
    merge2 = pivot - low + 1;

    for (i = 0; i < length; i++) {
        if (merge2 <= high - low) {
            if (merge1 <= pivot - low) {
                if (working[merge1] > working[merge2])
                    a[i + low] = working[merge2++];
                else
                    a[i + low] = working[merge1++];
            } else
                a[i + low] = working[merge2++];
        } else
            a[i + low] = working[merge1++];
    }
}