#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 /* Максимальная длинна слова */
#define N   50 /* Максимальное количество слов */

void sort_words(char *x[], int y);
void swap(char **, char **);

int main(void)
{
    char word[MAX];
    char *x[N];
    int n = 0;
    int i = 0;

    printf("Введите слова. Для завершения ввода нажмите Ctrl + D:\n");

    for (i = 0; scanf("%s", word) == 1; ++i) {
        if (i >= N)
            printf("Достигнут лимит: %d\n", N), exit(1);

        x[i] = calloc(strlen(word) + 1, sizeof(char));
        strcpy(x[i], word);
    }

    n = i;

    printf("\nРезультат:\n");

    sort_words(x, n);

    for (i = 0; i < n; ++i)
        printf("%s\n", x[i]);

    return 0;
}

void sort_words(char *x[], int y)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < y; ++i) {
        for (j = i + 1; j < y; ++j) {
            if (strcmp(x[i], x[j]) > 0)
                swap(&x[i], &x[j]);
        }
    }
}

void swap(char **p, char **q)
{
    char *tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}