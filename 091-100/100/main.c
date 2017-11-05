#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/cdrom.h>

/* Закрыть DVD-ROM */
int cdr_close(char *dev) {
    int fd;

    if (fd = open(dev, (O_RDONLY | O_NONBLOCK)) == -1)
        return -1;
    else if (ioctl(fd, CDROMCLOSETRAY) == -1)
        return -1;
    else
        close(fd);

    return 0;
}

/* Извлечь DVD-ROM */
int cdr_eject(char *dev) {
    int fd;

    if ((fd = open(dev, O_RDONLY | O_NONBLOCK)) == -1)
        return -1;
    else if (ioctl(fd, CDROMEJECT) == -1)
        return -1;
    else
        close(fd);

    return 0;
}

/* Блокировка DVD-ROM */
int cdlock(char *dev, int lock) {
    int fd;

    if ((fd = open(dev, O_RDONLY | O_NONBLOCK)) == -1)
        return -1;
    else if (ioctl(fd, CDROM_LOCKDOOR, lock) == -1)
        return -1;
    else
        close(fd);

    return 0;
}