//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Определяем максимум среди трёх чисел
#include <stdio.h>

int main(void) {

    double n1,n2,n3;

    printf("Введите три числа: ");
    scanf("%lf %lf %lf",&n1,&n2,&n3);

    if (n1>=n2&&n1>=n3) {

        printf("%.2f - максимум.\n",n1);

    }

    if (n2>=n1&&n2>=n3) {

        printf("%.2f - максимум.\n",n2);

    }

    if (n3>=n1&&n3>=n2) {

        printf("%.2f - максимум.\n",n3);

    }

    return 0;

}
