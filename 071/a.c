#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

struct node *next = NULL;

/* Функция вставляет узел в правильное место связного списка */
void insert_node(int value);

/* Сортировка вставками */
int main(void)
{
    struct node *current = NULL;
    struct node *next = NULL;
    int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
    int i = 0;

    /* Вставляем некоторые элементы в связный список */
    for (i = 0; i < 10; i++)
        insert_node(test[i]);

    printf(" До  после\n"), i = 0;

    while (head->next != NULL) {
        printf("%4d\t%4d\n", test[i++], head->number);
        head = head->next;
    }

    /* Очищаем список */
    for (current = head; current != NULL; current = next)
        next = current->next, free(current);

    return 0;
}

void insert_node(int value)
{
    struct node *temp = NULL;
    struct node *one = NULL;
    struct node *two = NULL;

    /* Если список пуст нужно выделить память под голову списка */
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node *));
        head->next = NULL;
    }

    /* Первый элемент - голова, второй - следующий элемент */
    one = head;
    two = head->next;

    /* Временный узел */
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->number = value;

    /* Меняем one и two местами в случае необходимости */
    while (two != NULL && temp->number < two->number) {
        one = one->next;
        two = two->next;
    }

    one->next = temp;
    temp->next = two;
}


