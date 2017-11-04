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
                break;
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
































