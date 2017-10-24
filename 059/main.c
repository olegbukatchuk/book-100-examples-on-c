//
// Created by Oleg Bukatchuk on 24/10/2017.
//

// Сортировка элементов
#include <stdio.h>
#include <string.h>

int main(void) {

    int i,j;
    char str[10][50],temp[50];

    printf("Введите 10 слов:\n");

    for (i=0;i<10;++i) {

        scanf("%s[^\]",str[i]);

    }

    for (i=0;i<9;++i) {

        for (j=i+1;j<10;++j) {

            if (strcmp(str[i],str[j])>0) {

                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);

            }

        }

    }

    printf("\nВ лексикографическом порядке: \n");

    for (i=0;i<10;++i) {

        puts(str[i]);

    }

    return 0;

}