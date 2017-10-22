//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Вычисляем максимум массива
#include <stdio.h>

int main(void) {

    int i,n;
    float arr[100];

    printf("Введите количество элементов массива (1-100): ");
    scanf("%d",&n);
    printf("\n");

    // Читаем ввод пользоватя
    for (i=0;i<n;++i) {

        printf("Введите элемент %d: ",i+1);
        scanf("%f",&arr[i]);

    }

    // Проходимся по массиву сохраняя наибольший элемент в arr[0]
    for (i=1;i<n;++i) {

        // Если arr[0] меньше текущего значения значит у нас есть новый максимум
        if (arr[0]<arr[i]) {

            arr[0]=arr[i];

        }

    }

    printf("Максимум = %.2f\n",arr[0]);

    return 0;

}