//
// Created by Oleg Bukatchuk on 24/10/2017.
//

// Удаляем все символы в строке кроме цифровых (не работает)
#include <stdio.h>

int main() {

    char line[1500];
    int i,j;

    printf("Введите строку: ");
    gets(line);

    for (i=0;line[i]!='\0';++i) {

        while (!((line[i]>='0'&&line[i]<='9')||line[i]=='\0')) {

            for (j=1;line[j]!='\0';++j) {

                line[j]=line[j+1];

            }

            line[j]='\0';

        }

    }

    printf("Результат: ");
    puts(line);

    return 0;

}