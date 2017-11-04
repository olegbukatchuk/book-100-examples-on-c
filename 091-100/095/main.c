#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE * uptimefile;
    char uptime_chr[28];
    long uptime = 0;

    if ((uptimefile = fopen("/proc/uptime", "r")) == NULL)
        perror("supt"), exit(EXIT_FAILURE);

    fgets(uptime_chr, 12, uptimefile);
    fclose(uptimefile);

    uptime = strtol(uptime_chr, NULL, 10);

    printf("Система работает %ld секунд, %ld часов\n", uptime, uptime / 3600);

    exit(EXIT_SUCCESS);
}