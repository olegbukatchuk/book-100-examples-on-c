//
// Created by Oleg Bukatchuk on 26/10/2017.
//

// Структуры и динамическое выделение памяти
#include <stdio.h>
#include <stdlib.h>

struct course {

    int marks;
    char subject[30];

};

int main(void) {

    struct course *ptr;
    int i,noOfRecords;

    printf("Количество записей: ");
    scanf("%d",&noOfRecords);

    // Выделяем память, ptr будет указывать на базовый адрес
    ptr=(struct course*)malloc(noOfRecords*sizeof(struct course));

    for (i=0;i<noOfRecords;++i) {

        printf("Введите название предмета и оценку:\n");
        scanf("%s %d",&(ptr+i)->subject,&(ptr+i)->marks);

    }

    printf("Результат:\n");

    for (i=0;i<noOfRecords;++i) {

        printf("%s\t%d\n",(ptr+i)->subject,(ptr+i)->marks);

    }

    return 0;

}

