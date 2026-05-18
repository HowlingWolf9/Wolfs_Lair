#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  struct sockaddr_in client, server;
  int lfd;
  char rBuf[100] = "", sBuf[100] = "";

  lfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = 2001;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (bind(lfd, (struct sockaddr *)&server, sizeof server) < 0) {
    perror("Bind failed.");
    close(lfd);
    return 1;
  };

  printf("\nServer ready, waiting for client....\n");
  socklen_t n = sizeof client;

  recvfrom(lfd, rBuf, sizeof rBuf, 0, (struct sockaddr *)&client, &n);
  printf("\nClient: %s", rBuf);
  printf("\nServer: ");
  scanf("%s", sBuf);
  sendto(lfd, sBuf, sizeof sBuf, 0, (struct sockaddr *)&client, n);
  printf("\n");

  close(lfd);
  return 0;
}