//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Определяем количество цифр в целом числе
#include <stdio.h>

int main(void) {

    long long n;
    int count=0;

    printf("Введите целое число: ");
    scanf("%lld",&n);

    while (n!=0) {

        n/=10;
        ++count;

    }

    printf("Количество цифр: %d\n",count);

    return 0;

}