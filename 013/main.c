#include <stdio.h>
#include <math.h>

/* Вычисляем все квадратные корни */
int main(void)
{
    double a, b, c, determinant, root1, root2, realPart, imaginaryPart;

    printf("Введите коэффициенты a, b, и c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    determinant = b * b - 4 * a * c;

    if (determinant > 0) {
        /* sqrt() - возвращает квадратный корень */
        root1 = (-b + sqrt(determinant)) / (2 * a);
        root2 = (-b - sqrt(determinant)) / (2 * a);
        printf("root1 = %.2lf и root2 = %.2lf\n", root1, root2);
    } else if (determinant == 0) {
        /* когда корень один */
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;\n", root1);
    } else {
        /* если корни комплексные */
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-determinant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi и root2 = %.2lf-%.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
