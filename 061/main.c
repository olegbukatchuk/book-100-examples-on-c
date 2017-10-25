//
// Created by Oleg Bukatchuk on 25/10/2017.
//

// Сложение двух структур
#include <stdio.h>

struct Dustance {

    int feet;
    float m;

} d1,d2,sumOfDistances;

int main(void) {

    printf("Заполняем первую структуру\n");
    printf("Количество шагов: ");
    scanf("%f",&d1.m);
    printf("Количество метров: ");
    scanf("%f",&d1.m);

    printf("\nЗаполняем вторую структуру\n");
    printf("Количество шагов: ");
    scanf("%d",&d2.feet);
    printf("Количество метров: ");
    scanf("%d",&d2.feet);

    sumOfDistances.feet=d1.feet+d2.feet;
    sumOfDistances.m=d1.m+d2.m;

    printf("\nРезультат = %d - %.1f\n",sumOfDistances.feet,sumOfDistances.m);

    return 0;

}