
#include <stdio.h>

/* Поиск частоты знаков в строке */
int main()
{
    char str[100], ch;
    int i, frequency = 0;

    printf("Введите строку: ");
    gets(str);

    printf("Введите символ: ");
    scanf("%c", &ch);

    for (i = 0; str[i] != '\0'; ++i) {
        if (ch == str[i])
            ++frequency;
    }

    printf("Частота = %d\n",frequency);

    return 0;
}