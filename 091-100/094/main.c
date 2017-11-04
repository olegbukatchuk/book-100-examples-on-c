#include <stdio.h>
#include <termios.h>

#define PASSMAX 8

int main(void)
{
    struct termios defrsett, newrsett;
    char password[PASSMAX + 1];

    tcgetattr(fileno(stdin), &defrsett);

    newrsett = defrsett;
    newrsett.c_lflag &= ~ECHO;

    printf("Введите пароль: ");

    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newrsett) != 0)
        fprintf(stderr, "Не установлены атрибуты\n");
    else {
        fgets(password, PASSMAX, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &defrsett);
        fprintf(stdout, "\nВведённый пароль %s", password);
    }

    printf("\n");

    return 0;

    return 0;
}