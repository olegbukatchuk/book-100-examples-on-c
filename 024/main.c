//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Вычисляем общее кратное
#include <stdio.h>

int main(void) {

    int n,reverseNumber=0,remainder;

    printf("Введите целое число: ");
    scanf("%d",&n);

    while (n!=0) {

        remainder=n%10;
        reverseNumber=reverseNumber*10+remainder;
        n/=10;

    }

    printf("Обратное число = %d\n",reverseNumber);

    return 0;

}
