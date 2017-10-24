//
// Created by Oleg Bukatchuk on 24/10/2017.
//

// Удаляем все символы в строке кроме цифровых
#include <stdio.h>

int main(void) {

    char line[150];
    int i,total,digits,spaces;

    total=digits=spaces=0;

    printf("Введите строку ");
    scanf("%[^\n]",line);

    for (i=0;line[i]!='\0';++i) {

        if (line[i]>='0'&&line[i]<='9') {

            ++digits;

        }

        else if (line[i]==' ') {

            ++spaces;

        }

        ++total;

    }

    printf("Всего символов: %d",total);
    printf("\nЦифр: %d",digits);
    printf("\nПробелов: %d\n",spaces);

    return 0;

}