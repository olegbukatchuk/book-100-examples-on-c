//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Сложение двух матриц с использованием многомерных массивов
#include <stdio.h>

int main(void) {

    int r,c,a[100][100],b[100][100],sum[100][100],i,j;

    printf("Введите количество строк от 1 до 100: ");
    scanf("%d",&r);
    printf("Введите количество колонок от 1 до 100: ");
    scanf("%d",&c);

    printf("\nВведите элементы первой матрицы:\n");

    for (i=0;i<r;++i) {

        for (j=0;j<c;++j) {

            printf("Введите элемент a%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);

        }

    }

    printf("Введите элементы второй матрицы:\n");

    for (i=0;i<r;++i) {

        for (j=0;j<c;++j) {

            printf("Введите элемент b%d%d: ",i+1,j+1);
            scanf("%d",&b[i][j]);

        }

    }

    // Сложение 2 матриц
    for (i=0;i<r;++i) {

        for (j=0;j<c;++j) {

            sum[i][j]=a[i][j]+b[i][j];

        }

    }

    // Отображаем результат
    printf("\nСумма 2 матриц: \n\n");

    for (i=0;i<r;++i) {

        for (j=0;j<c;++j) {

            printf("%d   ",sum[i][j]);

            if (j==c-1) {

                printf("\n\n");

            }

        }

    }

    return 0;

}