#include <stdio.h>

void bubble_sort(int a[], int size);

int main(void)
{
    int arr[10] = {10, 2, 4, 1, 6, 5, 8, 7, 3, 9};
    int i = 0;

    printf("До сортировки:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bubble_sort(arr, 10);

    printf("После:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void bubble_sort(int a[], int size)
{
    int switched = 1;
    int hold = 0;
    int i = 0;
    int j = 0;

    size -= 1;

    for (i = 0; i < size && switched; i++) {
        switched = 0;
        for (j = 0; j < size - i; j++)
            if (a[j] > a[j + 1]) {
                switched = 1;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
    }
}