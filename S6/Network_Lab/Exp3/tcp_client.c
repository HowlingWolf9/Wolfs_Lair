#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  struct sockaddr_in server;
  int lfd;
  char rBuf[100] = "", sBuf[100] = "";

  lfd = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = 2000;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("\nClient ready....\n");
  if (connect(lfd, (struct sockaddr *)&server, sizeof server) < 0) {
    perror("Connection failed");
    close(lfd);
    return 1;
  }

  printf("\nClient: ");
  scanf("%s", sBuf);
  send(lfd, sBuf, sizeof sBuf, 0);
  recv(lfd, rBuf, sizeof rBuf, 0);

  printf("Server: %s", rBuf);
  printf("\n\n");

  close(lfd);

  return 0;
}