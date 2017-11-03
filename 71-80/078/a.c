#include <stdio.h>

void isort(float arr[], int n);
int fm(float arr[], int b, int n);

int main(void)
{
    float arr1[5] = {4.3, 6.7, 2.8, 8.9, 1.0};
    float arr2[5] = {4.3, 6.7, 2.8, 8.9, 1.0};
    int i = 0;

    isort(arr2, 5);

    printf("\nДо\tПосле\n---------------------\n");

    for (i = 0; i < 5; i++)
        printf("%.2f\t%.2f\n", arr1[i], arr2[i]);

    return 0;
}

int fm(float arr[], int b, int n)
{
    int f = b;
    int c;

    for (c = b + 1; c < n; c++) {
        if (arr[c] < arr[f])
            f = c;
    }

    return f;
}

void isort(float arr[], int n)
{
    int s, w;
    float sm;

    for (s = 0; s < n - 1; s++) {
        w = fm(arr, s, n);
        sm = arr[w];
        arr[w] = arr[s];
        arr[s] = sm;
    }
}