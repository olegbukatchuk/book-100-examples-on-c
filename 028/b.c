//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Выводим простые числа между a и b (между low и high)
#include <stdio.h>

int main(void) {

    int low,high,i,flag,temp;

    printf("Выводим простые числа между a и b, введите a и b: ");
    scanf("%d %d",&low,&high);

    if (low>high) {

        temp=low;
        low=high;
        high=temp;

    }

    while (low<high) {

        flag=0;

        for (i=2;i<=low/2;++i) {

            if (low%i==0) {

                flag=1;

                break;

            }

        }

        if (flag==0) {

            printf("%d \n",low);

        }

        ++low;

    }

    printf("\n");

    return 0;

}