//
// Created by Oleg Bukatchuk on 24/10/2017.
//

// Конкатенация двух строк без функции strcat()
#include <stdio.h>

int main(void) {

    char s1[100],s2[100],i,j;

    printf("Первая строка: ");
    scanf("%s",s1);

    printf("Вторая строка: ");
    scanf("%s",s2);

    // вычисляем длину s1 и помещаем её в i
    for (i=0;s1[i]!='\0';++i);

    for (j=0;s2[j]!='\0';++j,++i) {

        s1[i]=s2[j];

    }

    s1[i]='\0';
    printf("Результат: %s\n",s1);

    return 0;

}