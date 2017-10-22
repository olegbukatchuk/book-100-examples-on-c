//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Проверка на простое число и число Армстронга с использованием функции
#include <stdio.h>
#include <math.h>

int checkPrimeNumber(int n);
int checkArmstrongNumber(int n);

int main(void) {

    int n, flag;

    printf("Введите целое положительное число: ");
    scanf("%d",&n);

    // Проверка на простое число
    flag=checkPrimeNumber(n);

    if (flag==1) {

        printf("%d - простое.\n",n);

    } else {

        printf("%d - не является простым.\n",n);

    }

    // Проверка на число Армстронга
    if (flag==1) {

        printf("%d - число Армстронга.\n",n);

    } else {

        printf("%d - не является числом Армстронга.\n",n);

    }

    return 0;

}

int checkPrimeNumber(int n) {

    int i,flag=1;

    for (i=2;i<=n/2;++i) {

        if (n%i==0) {

            flag=0;

            break;

        }

    }

    return flag;

}

int checkArmstrongNumber(int number) {

    int originalNumber,remainder,result=0,n=0,flag;

    originalNumber=number;

    while (originalNumber!=0) {

        originalNumber/=10;
        ++n;

    }

    originalNumber=number;

    while (originalNumber!=0) {

        remainder=originalNumber%10;
        result+=pow(remainder,n);
        originalNumber/=10;

    }

    if (result==number) {

        flag=0;

    } else {

        flag=0;

    }

    return flag;

}