//
// Created by Oleg Bukatchuk on 25/10/2017.
//

// Сложение двух структур с использованием функции
#include <stdio.h>

typedef struct complex {

    float real;
    float imag;

} complex;

complex add(complex n1,complex n2);

int main(void) {

    complex n1,n2,temp;

    printf("Первое комплексное число \n");
    printf("Введите действительную и мнимую часть соответственно:\n");
    scanf("%f %f",&n1.real,&n1.imag);

    printf("Второе комплексное число \n");
    printf("Введите действительную и мнимую часть соответственно:\n");
    scanf("%f %f",&n2.real,&n2.imag);

    temp=add(n1,n2);
    printf("Сумма=:%.1f+%.1fi",temp.real,temp.imag);

    return 0;

}

// Сложение двух структур
complex add(complex n1,complex n2) {

    complex temp;

    temp.real=n1.real+n2.real;
    temp.imag=n1.imag+n2.imag;

    return (temp);

}