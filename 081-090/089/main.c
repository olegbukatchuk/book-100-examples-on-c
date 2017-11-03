#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

int main(void)
{
    openlog("slog", LOG_PID | LOG_CONS, LOG_USER);

    syslog(LOG_INFO, "Hello world ... ");

    closelog();

    return 0;
}