#include <stdio.h>

int main(void)
{
    char tmpname[L_tmpnam];
    char *filename = NULL;
    FILE *tmpfp;

    filename = tmpnam(tmpname);

    printf("Временный файл: %s\n", filename);

    tmpfp = tmpfile();

    if (tmpfp)
        printf("Открытий файла: OK\n");
    else
        perror("tmpfile");

    return 0;
}