#include <stdio.h>
#include <stdlib.h>

/* Максимальная длинна массива */
#define MAXarRAY 5

/* Пирамидальная сортировка */
void heapsort(int ar[],int len);
/* Помогает heapsort() "выталкивать" элементыб начиная с позиции pos */
void heapbubble(int pos, int ar[], int len);

int main(void)
{
    int array[MAXarRAY];
    int i = 0;

    /* Загружаем случайные элементы в массиве */
    for (i = 0; i < MAXarRAY; i++)
        array[i] = rand() % 100;

    /* Выводим исходный массив */
    printf("До сортировки: ");

    for (i = 0; i < MAXarRAY; i++)
        printf(" %d ", array[i]);

    printf("\n");

    /* Сортировка */
    heapsort(array, MAXarRAY);

    printf("После сортировки: ");

    for (i = 0; i < MAXarRAY; i++)
        printf(" %d ", array[i]);

    printf("\n");
    return 0;
}

void heapbubble(int pos, int ar[], int len)
{
    int z = 0;
    int max = 0;
    int tmp = 0;
    int left = 0;
    int right = 0;

    z = pos;

    for (;;) {
        left = 2 * z + 1;
        right = left + 1;

        if (left >= len)
            return;
        else if (right >= len)
            max = left;
        else if (array[left] > array[right])
            max = left;
        else
            max = right;

        if (array[z] > array[max])
            return;

        tmp = array[z];
        array[z] = array[max];
        array[max] = tmp;
        z = max;
    }
}

void heapsort(int array[],int len)
{
    int i = 0;
    int tmp = 0;

    for (i = len / 2; i >= 0; --i)
        heapbubble(i, array, len);

    for (i = len - 1; i > 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heapbubble(0, array, i);
    }
}