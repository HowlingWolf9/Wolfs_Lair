#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  struct sockaddr_in server, client;
  int sockfd, connfd, n;
  char req[100], fname[256], buf[1024];
  int code;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_port = htons(2000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sockfd, (struct sockaddr *)&server, sizeof(server));
  listen(sockfd, 1);

  printf("Server ready, waiting for client...\n");
  n = sizeof(client);
  connfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&n);
  printf("Client connected\n");

  recv(connfd, req, sizeof(req), 0);

  while (strcmp(req, "close") != 0) {
    if (strcmp(req, "get") == 0) {
      code = 1;
      send(connfd, &code, sizeof(code), 0);
      recv(connfd, fname, sizeof(fname), 0);
      printf("Requested file: %s\n", fname);

      FILE *fp = fopen(fname, "rb");
      if (fp == NULL) {
        code = 2;
        send(connfd, &code, sizeof(code), 0);
        printf("File not found\n");
      } else {
        code = 3;
        send(connfd, &code, sizeof(code), 0);
        fseek(fp, 0, SEEK_END);
        long fsize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        send(connfd, &fsize, sizeof(fsize), 0);
        while ((n = fread(buf, 1, sizeof(buf), fp)) > 0)
          send(connfd, buf, n, 0);
        fclose(fp);
        printf("File sent successfully\n");
      }
    } else {
      code = 4;
      send(connfd, &code, sizeof(code), 0);
    }
    recv(connfd, req, sizeof(req), 0);
  }

  printf("Closing connection\n");
  close(connfd);
  close(sockfd);

  return 0;
}
