//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// НОД - Наибольший общий делитель
// НОК - Наименьшее общей кратное

// Определяем НОК с помощью бесконечного цикла
#include <stdio.h>

int main(void) {

    int n1,n2,minMultiple;

    printf("Введите два целых числа: ");
    scanf("%d %d",&n1,&n2);

    n1=(n1>0)?n1:-n1;
    n2=(n2>0)?n2:-n2;

    while (n1!=n2) {

        if (n1>n2) {

            n1-=n2;

        } else {

            n2-=n1;

        }

    }

    printf("НОД - %d\n",n1);

    return 0;

}
