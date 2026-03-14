#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in server;
    int lfd;
    char rBuf[100] = "", sBuf[100] = "";

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    connect(lfd, (struct sockaddr *)&server, sizeof server);

    printf("\nClient: ");
    gets(sBuf);
    send(lfd, sBuf, sizeof sBuf, 0);
    recv(lfd, rBuf, sizeof rBuf, 0);

    printf("\nServer: %s", rBuf);
    printf("\n");

    close(lfd);

    return 0;
}