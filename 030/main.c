//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Выводим числа Армстронга в заданном диапазоне
#include <stdio.h>
#include <math.h>

int main(void) {

    int low,high,i,temp1,temp2,remainder,n=0,result=0;

    printf("Введите два числа (начало и конец диапазона): ");
    scanf("%d %d",&low,&high);
    printf("Выводим числа Армстронга:");

    for (i=low+1;i<high;++i) {

        temp2=i;
        temp1=i;

        // Количество разрядов
        while (temp1!=0) {

            temp1/=10;
            ++n;

        }

        // Результат содержит сумму цифр, возведённых в степень n
        while (temp2!=0) {

            remainder=temp2%10;
            result+=pow(remainder,n);
            temp2/=10;

        }

        // Проверяем является ли число числом Армстронга
        if (result==i) {

            printf("%d ",i);

        }

        // Сброс значений перед следующей интерацией
        n=0;
        result=0;

    }

    printf("\n");

    return 0;

}