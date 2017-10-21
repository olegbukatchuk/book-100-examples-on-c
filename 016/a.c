//
// Created by Oleg Bukatchuk on 21/10/2017.
//

// Вычисляем количество итераций цикла
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int k=0,i=0;

    while (k<7) {

        k=1+rand()%10;

        // printf("%d ",k);

        i++;

    }

    printf("Количество итераций %d\n",i);

    return 0;

}