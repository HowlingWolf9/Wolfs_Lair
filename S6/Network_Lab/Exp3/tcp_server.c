#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  struct sockaddr_in client, server;
  int lfd, confd;
  char rBuf[100] = "", sBuf[100] = "";

  lfd = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = 2000;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (bind(lfd, (struct sockaddr *)&server, sizeof server) < 0) {
    perror("Bind failed.");
    close(lfd);
    return 1;
  }
  listen(lfd, 1);

  printf("\nServer ready, waiting for client....\n");
  socklen_t n = sizeof client;
  confd = accept(lfd, (struct sockaddr *)&client, &n);
  recv(confd, rBuf, sizeof rBuf, 0);

  printf("\nClient: %s", rBuf);
  printf("\nServer: ");
  scanf("%s", sBuf);
  send(confd, sBuf, sizeof sBuf, 0);
  printf("\n");

  close(confd);
  close(lfd);

  return 0;
}