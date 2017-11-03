#include <stdio.h>

/* Храним информацию о студенте в структуре */
struct student {
    char name[50];
    int roll;
    int group;
} s;

int main(void)
{
    printf("Введите информацию:\n");

    printf("Имя: ");
    scanf("%s", s.name);

    printf("Номер билета: ");
    scanf("%d", &s.roll);

    printf("Номер группы: ");
    scanf("%d", &s.group);

    printf("Выводим информацию:\n");

    printf("Имя: ");
    puts(s.name);

    printf("Номер билета: %d\n", s.roll);

    printf("Номер группы: %d\n", s.group);

    return 0;
}