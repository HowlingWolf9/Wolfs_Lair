#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in client, server;
    int lfd, n, confd;
    char rBuf[100] = "", sBuf[100] = "";

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd, (struct sockaddr *)&server, sizeof server);
    listen(lfd, 1);

    printf("\nServer ready, waiting for client....\n");
    n = sizeof client;
    confd = accept(lfd, (struct sockaddr *)&client, &n);
    recv(confd, rBuf, sizeof rBuf, 0);

    printf("\nClient: %s", rBuf);
    printf("\nServer: ");
    gets(sBuf);
    send(confd, sBuf, sizeof sBuf, 0);
    printf("\n");

    close(confd);
    close(lfd);

    return 0;
}