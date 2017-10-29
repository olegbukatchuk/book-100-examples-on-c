#include <stdio.h>

/* Символ гласный или согласный */
int main(void)
{
    char c;
    int isLowercaseVowel, isUppercaseVowel;

    printf("Введите символ: ");
    scanf("%s", &c);

    /* Возвращает 1 (true) если c - гласный нижний регистр */
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');

    /* Возвращает 1 (true) если c - гласный верхний регистр */
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');

    if (isLowercaseVowel||isUppercaseVowel)
        printf("Введённый символ - гласный\n");
    else
        printf("Введённый символ - согласный\n");

    return 0;
}