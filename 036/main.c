//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Сумма n натуральных чисел с использованием рекурсии
#include <stdio.h>

int addNumbers(int n);

int main(void) {

    int num;

    printf("Введите положительное целое число: ");
    scanf("%d",&num);
    printf("Сумма = %d\n",addNumbers(num));

    return 0;

}

int addNumbers(int n) {

    if (n!=0) {

        return n+addNumbers(n-1);

    } else {

        return n;

    }

}