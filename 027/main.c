//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Является ли число простым
#include <stdio.h>

int main(void) {

    int n,i,flag=0;

    printf("Введите целое положительное число: ");
    scanf("%d",&n);

    for (i=2;i<=n/2;++i) {

        if (n%i==0) {

            flag=1;

            break;

        }

    }

    if (flag==0) {

        printf("%d - простое\n",n);

    } else {

        printf("%d - не является простым числом\n",n);

    }

    return 0;

}
