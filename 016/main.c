//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Вычисляем сумму натуральных чисел с помощью цикла
#include <stdio.h>

int main(void) {

    int n,i,sum=0;

    printf("Введите положительное целое число: ");
    scanf("%d",&n);

    for (i=1;i<=n;++i) {

        // sum = sum + i;
        sum+=i;

    }

    printf("Сумма = %d\n",sum);

    return 0;

}