#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* strptime() */
#define __USE_XOPEN

#define PACKAGE "utconv"
#define VERSION "0.0.1"

/* Выводим справку по использованию программы */
void print_help(int exval);

/* Извлекаем UTC-время из строки */
int get_utc(char *str);

/* Конвертирование UTC в строку */
char *convert_utc(int uval);

int main(int argc, char *argv[])
{
    int opt = 0;
    if (argc == 1)
        print_help(0);

    while ((opt = getopt(argc, argv, "hvu:s:")) != -1) {
        switch (opt) {
            case 'h':   /* Выводим справку и выходим */
                print_help(0);
                break;

            case 'v':   /* Выводим версию и выходим */
                fprintf(stdout, "%s %s\n", PACKAGE, VERSION);
                exit(0);
                break;

            case 'u':   /* Конвертируем INT utc в строку */
                printf("%s\n", convert_utc(atoi(optarg)));
                break;

            case 's':   /* Проверка корректности пользовательского ввода */
                if (strlen(optarg) < 23 || strlen(optarg) > 24) {
                    fprintf(stderr, "%s: Некорректный формат ? '%s'\n", PACKAGE, optarg);
                    fprintf(stderr, "%s: Строка должна быть в формате: 'Mon Mar 6 10:00:04 2017'\n\n", PACKAGE);

                    return 1;
                }
                printf("%d\n", get_utc(optarg));
                break;

            case '?':
                fprintf(stderr, "%s: Ошибка - нет такой опции '%c'\n", PACKAGE, optopt);
                print_help(1);

            case ':':
                fprintf(stderr, "%s: Ошибка опция '%c' требует аргумент\n", PACKAGE, optopt);
                print_help(1);
        } /* switch */
    }   /* while */

    return 0;
}

/* Конвертирование UTC в строку */
char *convert_utc(int uval)
{
    time_t timeval;
    char *tstr = NULL;

    timeval = uval;
    tstr = strdup(ctime(&timeval));

    /* Удаляем лишние прбельные символы */
    tstr[strlen(tstr) - 1] = '\0';

    free(tstr);

    return tstr;
}

/* Извлекаем UTC-время из строки */
int get_utc(char *str)
{
    struct tm timestruct;
    int retval = 0;

    /* Sun Sep 7 00:00:04 2003 */
    if (strptime(str, "%a %b %d %T %Ey", &timestruct) == 0)
        return -1;
    else {
        timestruct.tm_year -= 1900;
        timestruct.tm_isdst = -1;
    }

    retval = mktime(&timestruct);

    return retval;
}

/* Выводим справку по использованию программы */
void print_help(int exval)
{
    printf("%s,%s конвертируем время в формате UTC в строку и обратно\n", PACKAGE, VERSION);
    printf("Использование: %s [-h] [-v] [-s STR] [-u INT]\n\n", PACKAGE);

    printf(" -h        отображение этой информации\n");
    printf(" -v        информация о версии программы\n\n");
    printf(" -u INT    конвертирует UTC-время (целое число) в удобный для чтения формат\n");
    printf(" -s STR    конвертируем строку с временем в формат UTC\n");

    printf("           формат строки должен быть:\n");
    printf("           Mon Mar 6 10:00:04 2017\n\n");

    exit(exval);
}