// Игра змейка

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#ifdef MAC_OS_X_VERSION_10_13

// Библиотека нужна для функции Sleep().
#include <macos.h>

// Библиотека, нужна для использования функции kbhit() и getch().
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

#define STDIN_FILENO 0
#define NB_DISABLE   0
#define NB_ENABLE    1

#define Sleep(x)     usleep(x*1000)

int kbhit() {

    struct timeval tv;

    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);

    return FD_ISSET(STDIN_FILENO, &fds);

}

void nonblock(int state) {
    struct termios ttystate;

    // Получаем состояние терминала
    tcgetattr(STDIN_FILENO, &ttystate);

    if (state == NB_ENABLE) {

        // Выключаем ICANON-режим
        ttystate.c_lflag &= ~ICANON;
        ttystate.c_cc[VMIN] = 1;

    } else if (state == NB_DISABLE) {

        // Включаем ICANON-режим
        ttystate.c_lflag |= ICANON;

    }

    // Устанавливаем атрибуты терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);

}

int getch() {

    return fgetc(stdin);

}

#endif

// snake_size - Размер змейки.
// change_x, change_y - В какую сторону движется змейка.
// coordinates_x[1000], coordinates_y[1000] - Массивы, хранящие координаты частей тела змейки.
// coordinates_x[1], coordinates_y[1] - Координаты головы змейки.
// food_x, food_y - Координаты еды.

int snake_size, change_x, change_y, coordinates_x[1000], coordinates_y[1000];
int food_x = -1, food_y = -1;

// symbol - хранит в себе ASCII-код нажатой клавиши.
// a[1000][1000] - наша таблица, в которой происходит вся игра.
char symbol, a[1000][1000];

// Константы:
// N - Высота таблицы.
// M - Ширина таблицы.
// INTERVAL - Интервал в миллисекундах, через каждый этот промежуток времени змейка будет передвигаться.
const int N = 13, M = 17, INTERVAL = 200;

// Функция считывает нажатую клавишу.
void change_direction() {

    // Считываем нажатую клавишу с помощью функции getch().
    symbol = getch();

    switch (symbol) {

        // Управление змейкой через wasd.
        case 'w': if (change_x != 0 || change_y != 0) {

                change_x = -1;
                change_y = 0;

            }

            break;

        case 'a': if (change_x != 0 || change_y != 1) {

                change_x = 0;
                change_y = -1;

            }

            break;

        case 's': if (change_x != -1 || change_y != 0) {

                change_x = 1;
                change_y = 0;

            }

            break;

        case 'd': if (change_x != 0 || change_y != -1) {

                change_x = 0;
                change_y = 1;

            }

            break;

#ifdef MAC_OS_X_VERSION_10_13
            case 'q': nonblock(NB_DISABLE); std:exit(0);
#endif
            default: break;

    }

}

// Функция для вывода таблицы
void show_table() {

    // Очищаем консоль.
#ifdef MAC_OS_X_VERSION_10_13
    system("cls");
#else
    system("clear");
#endif

    // Выводим таблицу и края.
    for (int i=0; i<=N+1; ++i) {

        for (int j=0; j<=M+1; ++j) {

            std::cout << (i==0 || j==0 || i==N+1 || j==M+1 ? '#' : a[i][j]) << (j<=M ? "" : "\n");

        }

    }

}

// Очищаем координаты в которых располагалась змейка.
void clear_snake_on_table() {

    for (int i=1; i<=snake_size; ++i) {

        

    }

}