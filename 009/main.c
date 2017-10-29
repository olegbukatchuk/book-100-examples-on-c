#include <stdio.h>

/* Меняем местами два числа */
int main(void)
{
    double A, B, temp;

    printf("Введите A: ");
    scanf("%lf", &A);

    printf("Введите B: ");
    scanf("%lf", &B);

    temp = A;

    A = B;

    B = temp;

    printf("\nПосле замены, A = %.2lf\n", A);
    printf("После замены, B = %2.lf\n", B);

    return 0;
}

