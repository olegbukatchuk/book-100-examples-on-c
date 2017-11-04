#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct stat file_stats;

    if (argc != 2)
        fprintf(stderr, "Usage: fstat FILE...\n"), exit(EXIT_FAILURE);

    if ((stat(argv[1], &file_stats)) == -1) {
        perror("fstat");
        return 1;
    }

    printf("Имя файла: %s\n",                               argv[1]);
    printf(" Устройство: %d\n",                             file_stats.st_dev);
    printf(" Инод: %llu\n",                                 file_stats.st_ino);
    printf(" Число жестких ссылок: %d\n",                   file_stats.st_nlink);
    printf(" UID владельца: %d\n",                          file_stats.st_uid);
    printf(" GID владельца: %d\n",                          file_stats.st_gid);
    printf(" Тип устройства (если это устройство): %d\n",   file_stats.st_rdev);
    printf(" Общий размер в байтах: %lld\n",                file_stats.st_size);
    printf(" Размер блока файловой системы, байты: %d\n",   file_stats.st_blksize);
    printf(" Число выделенных блоков: %lld\n",              file_stats.st_blocks);
    printf(" Время последнего доступа: %ld : %s\n",         file_stats.st_atime, ctime(&file_stats.st_mtime));
    printf(" Время создания: %ld : %s",                     file_stats.st_ctime, ctime(&file_stats.st_ctime));

    return 0;
}