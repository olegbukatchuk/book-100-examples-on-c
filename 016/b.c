//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Сумма натуральных чисел с помощью цикла while()
#include <stdio.h>

int main(void) {

    int n,i,sum=0;

    printf("Введите n: ");
    scanf("%d",&n);

    i=1;

    while (i<=n) {

        sum+=i;
        ++i;

    }

    printf("Сумма = %d\n",sum);

    return 0;

}
