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

        a[coordinates_x[i][coordinates_y[i]]] = '';

    }

}

// Красим координаты змейки.
void show_snake_on_table() {

    // Изменяем тип головы.
    if (change_x == 1 && change_y == 0) {

        a[coordinates_x[1]][coordinates_y[1]] = 'v';

    }

    if (change_x == -1 && change_y == 0) {

        a[coordinates_x[1]][coordinates_y[1]] = '^';

    }

    if (change_x == 0 && change_y == 1) {

        a[coordinates_x[1]][coordinates_y[1]] = '>';

    }

    if (change_x == 0 && change_y == -1) {

        a[coordinates_x[1]][coordinates_y[1]] = '<';

    }

    // Красим змейку
    for (int i=2; i<=snake_size; ++i) {

        a[coordinates_x[1]][coordinates_y[1]] = '@';

    }

}

// Проверяем съела ли змейка саму себя.
bool game_over() {

    for (int i=2; i<=snake_size; ++i) {

        // Если координаты головы змейки равны координате какой-либо части тела змейки,
        // то змейка съела саму себя.
        if (coordinates_x[1] == coordinates_y[i] && coordinates_y[1] == coordinates_y[i]) {

            return true;

        }

    }

    // Если координаты головы змейки НЕ равны координате какой-либо части тела змейки,
    // то всё в порядке игра продолжается.
    return false;

}

// Проверяем не вышла ли змейка за поле, если да, то возвращаем её обратно.
void  check_coordinates() {

    if (coordinates_x[1] > N) {

        coordinates_x[1] = 1;

    }

    if (coordinates_x[1] < 1) {

        coordinates_x[1] = N;

    }

    if (coordinates_y[1] > M) {

        coordinates_y[1] = 1;

    }

    if (coordinates_y[1] < 1) {

        coordinates_y[1] = M;

    }

}

// Функция следующего хода в которой наша змейка сдвигается в сторону на 1 ячейку.
void next_step() {

    // Чистим таблицу от змейки.
    clear_snake_on_table();

    // Передвигаем тело змейки.
    for (int i=snake_size; i>=2; --i) {

        coordinates_x[i] = coordinates_x[i-1];
        coordinates_y[i] = coordinates_y[i-1];

    }

    // Передвигаем голову змейки.
    coordinates_x[1] += change_x;
    coordinates_y[1] += change_y;

    // Проверяем в порядке ли координаты.
    check_coordinates();

    // Если голова змейки там же, где и еда, то увеличиваем размер змейки и очищаем координаты змейки.
    if (coordinates_x[1] == food_x && coordinates_y[1] == food_y) {

        snake_size++;
        food_x = -1;
        food_y = -1;

    }

    // Рисуем змейку.
    show_snake_on_table();

    // Если змейка укусила себя.
    if (game_over()) {

        //  Сообщаем всю правду об игроке.
        std::cout << "You're looser!\n";

        // Приостанавливаем игру.
#ifdef MAC_OS_X_VERSION_10_13
        system("pause");
#endif
        // Завершаем программу.
         std::exit(0);

    }

}

// Функция проверки на наличие еды на карте.
bool food_check() {

    // Если координаты еды неопределены, то возвращаем true.
    if (food_x==-1 && food_y==-1) {

        return false;

    }

    // В остальных случаях false.
    return true;

}

// Функция добавления еды на карту.
void place_food() {

    std::srand(std::time(NULL));

    // Ставим в рандомное место еду.
    for (int i=1; i<=9; ++i) {

        int x=std::rand(), y=std::rand();

        if (x < 0) {

            x *= -1;

        }

        if (y < 0) {

            y *= -1;

        }

        x %=(N+1);
        y %=(M+1);

        if (x == 0) {

            ++x;

        }

        if (y == 0) {

            ++y;

        }

        if (a[x][y] != '@' && a[x][y] != 'v' && a[x][y] != '^' && a[x][y] != '<' && a[x][y] != '>') {

            food_x = x;
            food_y = y;
            a[x][y] = '+';

            return;

        }

    }

}

// Начальные установки.
void standart_settings() {

    // Размер змейки - 2
    snake_size = 2;

    // Змейка занимает две клетки вправо от координаты {1,1}.
    coordinates_x[1] = 1;
    coordinates_y[1] = 2;
    coordinates_x[2] = 1;
    coordinates_y[2] = 1;

    // Змейка движется вправо.
    change_x = 0;
    change_y = 1;

}

int main() {

    // Задаём стандартные настройки.
    standart_settings();

#ifdef MAC_OS_X_VERSION_10_13
    std::memset(a, ' ', sizeof(a));
    nonblock(NB_ENABLE);
#endif

    // Бесконечный цикл.
    while (true) {

        // Если нажата клавиша, обрабатываем её.
        if (kbhit() != 0) {

            change_direction();

        }

        // Двигаем змейку.
        next_step();

        // Если нет еды, то раскладываем её.
        if (!food_check()) {

            place_food();

        }

        // Рисуем змейку.
        show_table();

        // "Усыпляем" программу на заданный интервал
        Sleep(INTERVAL);

    }

    return 0;
    
}

