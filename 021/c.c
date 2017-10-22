//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Определяем НОД с помощью цикла while
#include <stdio.h>

int main(void) {

    int n1,n2;

    printf("Введите два числа: ");
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