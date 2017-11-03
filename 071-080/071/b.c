#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *str;
    struct lnode *next;
};

/* Вставка и сортировка */
struct lnode *insert(char *data, struct lnode *list);

/* Освобождение памяти */
void free_list(struct lnode *list);

/* Вывод списка */
void print_list(struct lnode *list);

int main(void)
{
    char line[1024];
    struct lnode *list;

    list = NULL;

    while ((fgets(line, 1024, stdin)) != NULL)
        list = insert(line, list); /* Сортировка осуществляется при вставке */

    print_list(list); /* Выводим отсортированный список */
    free_list(list);  /* Освобождаем память */

    return 0;
}

struct lnode *insert(char *data, struct lnode *list)
{
    struct lnode *p;
    struct lnode *q;

    /* Создаём новый узел */
    p = (struct lnode *)malloc(sizeof(struct lnode));

    /* Сохраняем данные в новый узел */
    p->str = strdup(data);

    /* Сперва оьрабатываем случай, где данные (data) должны быть первым элементом */
    if (list == NULL || strcmp(list->str, data) > 0) {
        /*
         * По всей видимости, это первый элемент
         * теперь данные станут первым элементом
         */
        p->next = list;

        return p;
    } else {
        /*
         * Производим поиск по связному списку, определяя правильнуб позицию
         */
        q = list;

        while (q->next != NULL && strcmp(q->next->str, data) < 0)
            q = q->next;

        p->next = q->next;
        q->next = p;

        return list;
    }
}

void free_list(struct lnode *list)
{
    struct lnode *p;

    while (list != NULL) {
        p = list->next;
        free(list);
        list = p;
    }
}

void print_list(struct lnode *list)
{
    struct lnode *p;

    for (p = list; p != NULL; p = p->next)
        printf("%s", p->str);
}