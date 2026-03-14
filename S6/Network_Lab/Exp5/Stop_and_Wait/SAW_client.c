#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, total, pkt, ack, frame = 0, dummy = 1;
  struct sockaddr_in server;
  socklen_t len = sizeof(server);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  sendto(sockfd, &dummy, sizeof(dummy), 0, (struct sockaddr *)&server, len);

  recvfrom(sockfd, &total, sizeof(total), 0, (struct sockaddr *)&server, &len);
  printf("Total packets to receive: %d\n", total);

  while (1) {
    recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)&server, &len);
    if (pkt == -1)
      break;

    printf("Frame %d received: %d\n", frame, pkt);
    printf("packet %d (0=ACK, -1=NAK): ", pkt);
    scanf("%d", &ack);

    sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&server, len);
    if (ack == 0)
      frame++;
  }

  printf("All frames received successfully\nConnection closed\n");
  close(sockfd);
  return 0;
}
