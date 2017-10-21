#include <stdio.h>

// Умножение двух вещественных чисел
int main(void) {

  double firstNumber, secondNumber, product;

  printf("Введите два числа: ");
  scanf("%lf %lf",&firstNumber,&secondNumber);

  product=firstNumber+secondNumber;

  printf("%.2lf\n",product);

  return 0;

}
