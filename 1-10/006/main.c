#include <stdio.h>

/* Вычисляем частное и остаток от деления */
int main(void)
{
  int dividend, divisor, quotient, remainder;

  printf("Введите делимое: ");
  scanf("%d", &dividend);

  printf("Введите делитель: ");
  scanf("%d", &divisor);

  quotient = dividend / divisor;

  remainder = dividend % divisor;

  printf("Частное = %d\n", quotient);
  printf("Остаток = %d\n", remainder);

  return 0;
}
