#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, wsize, total, i, count, frame = 0;
  int pkt[100], ack[100];
  struct sockaddr_in server;
  socklen_t len = sizeof(server);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("Enter window size: ");
  scanf("%d", &wsize);
  sendto(sockfd, &wsize, sizeof(wsize), 0, (struct sockaddr *)&server, len);

  recvfrom(sockfd, &total, sizeof(total), 0, (struct sockaddr *)&server, &len);
  printf("Total packets to receive: %d\n", total);

  while (1) {
    recvfrom(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&server,
             &len);
    if (count == 0)
      break;

    recvfrom(sockfd, pkt, sizeof(int) * count, 0, (struct sockaddr *)&server,
             &len);

    printf("Frame %d received:", frame);
    for (i = 0; i < count; i++)
      printf(" %d", pkt[i]);
    printf("\n");

    for (i = 0; i < count; i++) {
      printf("packet %d (0=ACK, -1=NAK): ", pkt[i]);
      scanf("%d", &ack[i]);
    }

    sendto(sockfd, ack, sizeof(int) * count, 0, (struct sockaddr *)&server,
           len);
    frame++;
  }

  printf("All frames received successfully\nConnection closed\n");
  close(sockfd);
  return 0;
}