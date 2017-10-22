//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Определяем является ли символ алфавитным или нет
#include <stdio.h>

int main(void) {

    char c;

    printf("Введите символ: ");
    scanf("%c",&c);

    if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')) {

        printf("%c - алфавитный\n",c);

    } else {

        printf("%c - неалфавитный\n",c);

    }

    return 0;

}
