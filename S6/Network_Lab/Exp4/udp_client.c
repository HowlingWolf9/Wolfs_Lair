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
    int lfd, n;
    char rBuf[100] = "", sBuf[100] = "";

    lfd = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 2001;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    n = sizeof server;

    printf("\nClient: ");
    gets(sBuf);
    sendto(lfd, sBuf, sizeof sBuf, 0, (struct sockaddr *)&server, n);
    recvfrom(lfd, rBuf, sizeof rBuf, 0, (struct sockaddr *)&server, &n);

    printf("\nServer: %s", rBuf);

    close(lfd);

    return 0;
}