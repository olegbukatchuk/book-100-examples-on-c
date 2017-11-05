#include <stdio.h>
#include <regex.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <sys/types.h>

#define PACKAGE "myip"
#define VERSION "1.0.0"

#define PIEXEPR "([0-9]{1,3})\\.([0-9]{1,3}\\.([0-9]{1,3})\\.([0-9]{1,3})"
#define EMEXPR  ".*@.*\\.([a-zA-Z]{1,3})$"
#define UREXPR  "(href|src)="

void print_ipadd(FILE *fp);
void print_email(FILE *fp);
void print_url(FILE *fp);
void print_help(int exval);

int main(int argc, char *argv[])
{
    FILE *fp = stdin;
    int opt = 0;
    int em_set = 0;
    int ip_set = 0;
    int ur_set = 0;

    setlocale(LC_ALL, "");

    while ((opt = getopt(argc, argv, "hvieu")) != -1) {
        switch (opt) {
            case 'h':
                print_help(0);
                break;
            case 'v':
                fprintf(stdout, "%s %s\n", PACKAGE, VERSION);
                exit(0);
            case 'i':
                ip_set = 1;
                break;
            case 'e':
                em_set = 1;
                break;
            case 'u':
                ur_set = 1;
                break;
            case '?':
                fprintf(stderr, "%s: Нет такой опции '%c'\n\n", PACKAGE, optopt);
                print_help(1);
                break;
        }
    }

    if (argc == 1 || (ip_set == 0 && em_set == 0 && ur_set == 0))
        print_help(1);

    if ((optind - argc) == 0) {
        if (em_set == 1)
            print_email(fp);
        else if (ip_set == 1)
            print_ipadd(fp);
        else
            print_url(fp);
    } else {
        /* Проходимся по оставшимся аргументам */
        for (; optind < argc; optind++) {
            if (freopen(argv[optind], "r", fp) == NULL) {
                perror(argv[optind]);
                continue;
            }

            if (em_set == 1)
                print_email(fp);
            else if (ip_set == 1)
                print_ipadd(fp);
            else
                print_url(fp);
        } /* for */
    } /* else */

    fclose(fp);

    return 0;
}

void print_ipadd(FILE *fp)
{
    char line[1024];
    char *address = NULL;
    char delim[] = ",:;'/\"+-_{}[]<>*&^%$#@!?~/|\\= \t\r\n";
    int retval = 0;
    regex_t re;

    if (regcomp(&re, IPEXPR, REG_EXTENDED) != 0)
        return;

    while ((fgets(line, 1024, fp)) != NULL) {
        if (strchr(line, '.') == NULL)
            continue;

        address = strtok(line, delim);

        while (address != NULL) {
            if (strlen(address) <= 15) {
                if ((retval = regexec(&re, address, 0, NULL, 0)) == 0)
                    printf("%s\n", address);
            }

            address = strtok(NULL, delim);
        }
    }
}

void print_email(FILE *fp)
{
    char address[256];
    char line[1024];
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    int retval = 0;
    regex_t re;

    if (regcomp(&re, EMEXPR, REG_EXTENDED) != 0)
        return;

    while ((fgets(line, 1024, fp)) != NULL) {
        if (strchr(line, '@') == NULL && strchr(line, '.') == NULL)
            continue;

        for (ptr1 = line, ptr2 = address; *ptr1; ptr1++) {
            if (isalpha(*ptr1) || isdigit(*ptr1) || strchr(".-_@", *ptr1) != NULL)
                *ptr2++ = *ptr1;
            else {
                *ptr2 = '\0';

                if (strlen(address) >= 6 && strchr(address, '@') != NULL && strchr(address, '.') != NULL) {
                    if ((retval = regexec(&re, address, 0, NULL, 0)) == 0)
                        printf("%s\n", address);
                }

                ptr2 = address;
            }
        }
    }
}

void print_url(FILE *fp)
{
    char line[1024];
    char delim[] = "<> \t\n";
    char *url = NULL;
    int retval = 0;
    regex_t re;

    if (regcomp(&re, UREXPR, REG_ICASE | REG_EXTENDED) != 0)
        return;

    while ((fgets(line, 1024, fp)) != NULL) {
        url = strtok(line, delim);

        while (url != NULL) {
            if ((retval = regexec(&re, url, 0, NULL, 0)) == 0)
                printf("%s\n", url);

            url = strtok(NULL, delim);
        }
    }
}

void print_help(int exval)
{
    printf("%s,%s выводим e-mail, URL или IP-адреса, найденные в тексте\n", PACKAGE, VERSION);
    printf("%s [-h] [-v] [-i] [-e] [-u] ФАЙЛ...\n\n", PACKAGE);

    printf(" -h        Отображает эту справку\n");
    printf(" -v        Выводит номер версии\n\n");
    printf(" -i        Выводит IP-адреса\n");
    printf(" -e        Выводит e-mail адреса\n");
    printf(" -u        Выводит URL\n\n");

    exit(exval);
}





















