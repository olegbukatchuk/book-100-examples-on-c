//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Определяем является ли число положительным или отрицательным
#include <stdio.h>

int main(void) {

    double number;

    printf("Введите число: ");
    scanf("%lf",&number);

    if (number<0.0) {

        printf("Отрицательное.\n");

        // true если number > 0
    } else if (number>0.0) {

        printf("Положительное.\n");

    } else {

        // иначе
        printf("Вы ввели 0.\n");

    }

    return 0;

}
