//
// Created by Oleg Bukatchuk on 24/10/2017.
//

// Поиск частоты знаков в строке
#include <stdio.h>

int main() {

    char str[100],ch;
    int i,frequency=0;

    printf("Введите строку: ");
    gets(str);

    printf("Введите символ: ");
    scanf("%c",&ch);

    for (i=0;str[i]!='\0';++i) {

        if (ch==str[i]) {

            ++frequency;

        }

    }

    printf("Частота = %d\n",frequency);

    return 0;

}