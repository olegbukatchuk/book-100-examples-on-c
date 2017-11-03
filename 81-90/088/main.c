#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(void)
{
    char cmpname[256];
    struct utsname uts;

    if (gethostname(cmpname, 255) == 0)
        printf("gethostname  : %s\n", cmpname);

    if (uname(&uts) == 0) {
        printf("uts.name     : %s\n", uts.sysname);
        printf("uts.machine  : %s\n", uts.machine);
        printf("uts.nodename : %s\n", uts.nodename);
        printf("uts.release  : %s\n", uts.release);
        printf("uts.version  : %s\n", uts.version);
    }

    return 0;
}