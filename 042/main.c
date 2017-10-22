//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Выводим предложение в обратном порядке
#include <stdio.h>

void reverseSentence();

int main(void) {

    printf("Введите предложение: ");

    reverseSentence();

    printf("\n");

    return 0;

}

void reverseSentence() {

    char c;
    scanf("%c",&c);

    if (c!='\n') {

        reverseSentence();
        printf("%c",c);

    }

}