//
// Created by Oleg Bukatchuk on 22/10/2017.
//

// Выводим простые числа с помощью пользовательской функции
#include <stdio.h>

int checkPrimeNumber(int n);
void separator();

int main(void) {

    int n1,n2,i,flag;

    printf("Введите начало и конец диапазона чисел: ");
    scanf("%d %d",&n1,&n2);
    printf("Выводим простые числа в заданном диапазоне:");

    separator();

    for (i=n1+1;i<n2;++i) {

        // Будет равен 1 если число простое
        flag=checkPrimeNumber(i);

        if (flag==1) {

            printf("%d ",i);

        }

    }

    separator();

    return 0;

}

void separator() {

    printf("\n");

    for (int i=0;i<80;i++) {

        printf("=");

    }

    printf("\n");

}

// Пользовательская функция для проверки на простое число
int checkPrimeNumber(int n) {

    int j,flag=1;

    for (j=2;j<=n/2;++j) {

        if (n%j==0) {

            flag=0;

            break;

        }

    }

    return flag;

}