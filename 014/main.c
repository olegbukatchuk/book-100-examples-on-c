//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Является ли год высокосным
#include <stdio.h>

int main(void) {

    int year;

    printf("Введите год: ");
    scanf("%d",&year);

    if (year%4==0) {

        if (year%100==0) {

            // year - делится на 400, поэтому высокосный
            if (year%400==0) {

                printf("%d - высокосный\n",year);

            } else {

                printf("%d - невысокосный\n",year);

            }

        } else {

            printf("%d - высокосный\n",year);

        }

    } else {

        printf("%d - невысокосный\n",year);

    }

    return 0;

}