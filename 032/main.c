//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Простой калькулятор
#include <stdio.h>

int main(void) {

    char operator;
    double firstNumber,secondNumber;

    printf("Введите оператор (+, -, *, /): ");
    scanf("%c",&operator);

    printf("Введите два операнда: ");
    scanf("%lf %lf",&firstNumber,&secondNumber);

    switch (operator) {

        case '+':

            printf("%.1lf + %.1lf = %.1lf",firstNumber,secondNumber,firstNumber+secondNumber);

            break;

        case '-':

            printf("%.1lf - %.1lf = %.1lf",firstNumber,secondNumber,firstNumber-secondNumber);

            break;

        case '*':

            printf("%.1lf * %.1lf = %.1lf",firstNumber,secondNumber,firstNumber*secondNumber);

            break;

        case '/':

            if (secondNumber!=0) {

                printf("%.1lf / %.1lf = %.1lf",firstNumber,secondNumber,firstNumber/secondNumber);

            } else {

                printf("На ноль делить нельзя!");

                break;

            }

        default:

            printf("Ошибка! Неправильный оператор");

    }

    printf("\n");

    return 0;

}