#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buf[1024];
    int n, in, out;

    if (argc != 3) {
        fprintf(stderr, "Использование: append SOURCE TARGET\n");

        return 0;
    }

    /* Открываем первый файл для чтения */
    in = open(argv[1], O_RDONLY);

    /* Открываем второй файл для записи */
    out = open(argv[2], O_WRONLY | O_APPEND);

    /* Копируем данные из первого файла во второй */
    while ((n = read(in, buf, sizeof(buf))) > 0)
        write(out, buf, n);

    return 0;
}