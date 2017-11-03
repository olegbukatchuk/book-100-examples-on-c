#include <stdio.h>

/* Выводим предложение в обратном порядке */
void reverseSentence();

int main(void)
{
    printf("Введите предложение: ");

    reverseSentence();

    printf("\n");

    return 0;
}

void reverseSentence()
{
    char c;
    scanf("%c", &c);

    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}