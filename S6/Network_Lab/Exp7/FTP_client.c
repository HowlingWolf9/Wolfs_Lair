#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  struct sockaddr_in server;
  int sockfd;
  char req[100], fname[256], buf[1024];
  int code;
  long fsize, total;
  ssize_t n;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_port = htons(2000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("Client ready\n");
  connect(sockfd, (struct sockaddr *)&server, sizeof(server));
  printf("Connection established\n");

  printf("Enter request (get/close): ");
  scanf("%s", req);

  while (strcmp(req, "close") != 0) {
    send(sockfd, req, sizeof(req), 0);
    recv(sockfd, &code, sizeof(code), 0);

    if (code == 1) {
      printf("Enter filename: ");
      scanf("%s", fname);
      send(sockfd, fname, sizeof(fname), 0);
      recv(sockfd, &code, sizeof(code), 0);

      if (code == 2) {
        printf("ERROR: File not found\n");
      } else if (code == 3) {
        FILE *fp = fopen(fname, "wb");
        recv(sockfd, &fsize, sizeof(fsize), 0);
        total = 0;
        while (total < fsize) {
          n = recv(sockfd, buf, sizeof(buf), 0);
          fwrite(buf, 1, n, fp);
          total += n;
        }
        fclose(fp);
        printf("%s : File Transfer Complete\n", fname);
      }
    } else if (code == 4) {
      printf("Invalid Request\n");
    }

    printf("\nEnter request (get/close): ");
    scanf("%s", req);
  }

  send(sockfd, req, sizeof(req), 0);
  printf("Closing connection\n");
  close(sockfd);

  return 0;
}
