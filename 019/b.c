//
// Created by Oleg Bukatchuk on 22/10/2017.
//

#include <stdio.h>

int main(void) {

    int i,j;

    for (i=1;i<=9;i++) {

        for (j=1;j<=9;j++) {

            printf("%2d ",i*j);
        }

        printf("\n");

    }

    return 0;

}
