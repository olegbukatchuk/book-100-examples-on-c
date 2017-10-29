#include <stdio.h>

/* Вывод целого числа, введённого пользователем */
int main(void)
{
  int k;

  printf("Введите целое число: ");
  scanf("%d",&k);
  printf("Вы ввели: %d\n",k);

  return 0;
}
