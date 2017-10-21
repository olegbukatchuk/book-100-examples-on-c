//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Меняем местами два числа
#include <stdio.h>

int main(void) {

    double A,B;

    printf("Введите A: ");
    scanf("%lf",&A);

    printf("Введите B: ");
    scanf("%lf",&B);

    A=A-B;
    B=A+B;
    A=B-A;

    printf("\nПосле замены, A = %.2lf\n",A);
    printf("После замены, B = %2.lf\n",B);

    return 0;

}

