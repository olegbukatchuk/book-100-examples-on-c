#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct lnode {
    int data;
    struct lnode *next;
} *head, *visit;

/* Добавляем новый узел в связный список */
void llist_add(struct lnode **q, int num);

/* Выборочная сортировка списка */
void llist_selection_sort(void);

/* Выводим связный список */
void llist_print(void);

int main(void)
{
    /* Связный список */
    struct lnode *newnode = NULL;

    /* Общий счётчик */
    int i = 0;

    /* Добавляем в список случайные данные */
    for (i = 0; i < MAX; i++)
        llist_add(&newnode, (rand() % 100));

    head = newnode;

    printf("До:\n");

    llist_print();

    printf("После:\n");

    llist_selection_sort();

    llist_print();

    return 0;
}

/* Добавляем новый узел в связный список */
void llist_add(struct lnode **q, int num)
{
    struct lnode *temp;

    temp = *q;

    /* Если список пуст, создаём первый элемент */
    if (*q == NULL) {
        *q = malloc(sizeof(struct lnode));
        temp = *q;
    } else {
        /* Переходим к последнему узлу */
        while (temp->next != NULL)
            temp = temp->next;

        /* Добавляем узел в конец списка */
        temp->next = malloc(sizeof(struct lnode));
        temp = temp->next;
    }

    /* Назначаем данные последнему узлу */
    temp->data = num;
    temp->next = NULL;
}

/* Выводим связный список */
void llist_print(void)
{
    visit = head;

    /* Проходимся по списку и выводим его */
    while (visit != NULL) {
        printf("%d ", visit->data);
        visit = visit->next;
    }

    printf("\n");
}

/* Выборочная сортировка списка */
void llist_selection_sort(void)
{
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;
    struct lnode *d = NULL;
    struct lnode *tmp = NULL;

    a = c = head;

    while (a->next != NULL) {
        d = b = a->next;
        while (b != NULL) {
            if (a->data > b->data) {
                if (a == head) {
                    a->next = b->next;
                    b->next = a;
                    tmp = a;
                    a = b;
                    b = tmp;
                    head = a;
                    c = a;
                    d = b;
                    b = b->next;
                } else {
                    if (a == head) {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                        head = a;
                    } else {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        c->next = b;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                }
            } else {
                d = b;
                b = b->next;
            }
        }

        c = a;
        a = a->next;
    }
}