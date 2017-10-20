#include <stdio.h>

// Сумма двух целых чисел
int main(void) {

  int firstNumber, secondNumber, sum;

  printf("Введите два целых числа: ");

  scanf("%d %d",&firstNumber,&secondNumber);

  sum=firstNumber+secondNumber;

  printf("%d + %d = %d\n",firstNumber,secondNumber); 

  return 0;

}
