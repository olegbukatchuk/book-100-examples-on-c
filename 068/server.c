#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory.h>
#include <netinet/in.h>
#include <stdio.h>

#define SERVER_PORT 1234
#define BUF_SIZE    64
#define MSG_TO_SEND "Version\n"

/* Программа сервер */
int main()
{
    int sock1, sock2;
    int ans_len, total = 0;

    char  buffer[BUF_SIZE];

    struct sockaddr_in sin, client;

    sock1=socket(AF_INET, SOCK_STREAM, 0);
    memset((char *) &sin, '\0', sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = SERVER_PORT;

    bind(sock1,(struct sockaddr *) &sin, sizeof(sin));

    printf("Server running...\n");

    listen(sock1, 3);

    while (1) {
        ans_len = sizeof(client);
        sock2 = accept(sock1, &client, &ans_len);
        write(sock2, MSG_TO_SEND, sizeof(MSG_TO_SEND));

        total += 1;

        ans_len = read(sock2, buffer, BUF_SIZE);
        write(1, buffer, ans_len);

        printf("Client no %d\n", total);

        shutdown(sock2, 0);

        close(sock2);
    }
}