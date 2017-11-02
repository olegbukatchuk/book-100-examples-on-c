#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char *str;
};

/* Функция сравнения для qsort() */
static int cmpr(const void *a, const void *b);

int main(void)
{
    struct node **strarray = NULL;
    int i = 0, count = 0;
    char line[1024];

    while (fgets(line, 1024, stdin) != NULL) {
        /* Добавляем 1 элемент в массив */
        strarray = (struct node **)realloc(strarray, (count + 1) * sizeof(struct node *));

        /* Копируем данные в новый элемент (структуру) */
        strarray[count]->str = strdup(line);
        count++;
    }

    printf("До:\n");

    for (i = 0; i < count; i++)
        printf("[%d]->str: %s", i, strarray[i]->str);

    /* Передаём массив структур */
    qsort(strarray, count, sizeof(*strarray), cmpr);

    printf("\n--\nПосле:\n");

    for (i = 0; i < count; i++)
        printf("[%d]->str: %s", i, strarray[i]->str);

    printf("\n");

    /* Освобождаем память */
    for (i = 0; i < count; i++) {
        free(strarray[i]->str);
        free(strarray[i]);
        i++;
    }

    free(strarray);

    return 0;
}

/* Функция сравнения для qsort() */
static int cmpr(const void *a, const void *b)
{
    struct node * const *one = a;
    struct node * const *two = b;

    return strcmp((*one)->str, (*two)->str);
}