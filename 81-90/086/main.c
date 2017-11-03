#include <stdio.h>
#include <stdlib.h>

#define MAX 10  /* Максимум 10 элементов */

struct lnode {
    int number;
    struct lnode *next;
};

/* Добавляем lnode в начало списка */
void llist_add_begin(struct lnode **n, int val);

/* Реверс списка */
void llist_reverse(struct lnode **n);

/* Отображение списка */
void llist_display(struct lnode *n);

int main(void)
{
    struct lnode *new = NULL;

    int i = 0;

    /* Вставляем числа в список от 0 до 10 */
    for (i = 0; i < MAX; i++)
        llist_add_begin(&new, i);

    printf("исходный список:");

    llist_display(new);
    llist_reverse(&new);

    printf("список в обратном порядке:");

    llist_display(new);

    return 0;
}

/* Добавляем lnode в начало списка */
void llist_add_begin(struct lnode **n, int val)
{
    struct lnode *temp = NULL;

    /* Добавляем новый узел */
    temp = malloc(sizeof(struct lnode));
    temp->number = val;
    temp->next = *n;
    *n = temp;
}

/* Реверс списка */
void llist_reverse(struct lnode **n)
{
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;

    a = *n, b = NULL;

    while (a != NULL) {
        c = b, b = a, a = a->next;
        b->next = c;
    }

    *n = b;
}

/* Отображение списка */
void llist_display(struct lnode *n)
{
    while (n != NULL)
        printf(" %d", n->number), n = n->next;

    printf("\n");
}