#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, wsize, total_packets, i, count, frame = 0, ack;
  int packet_ids[100];
  struct sockaddr_in server;
  socklen_t len = sizeof(server);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9001);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("Enter window size: ");
  scanf("%d", &wsize);
  sendto(sockfd, &wsize, sizeof(wsize), 0, (struct sockaddr *)&server, len);

  recvfrom(sockfd, &total_packets, sizeof(total_packets), 0,
           (struct sockaddr *)&server, &len);
  printf("Total packets to receive: %d\n", total_packets);

  while (1) {
    recvfrom(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&server,
             &len);

    if (count == 0)
      break;

    recvfrom(sockfd, packet_ids, sizeof(int) * count, 0,
             (struct sockaddr *)&server, &len);

    printf("\nFrame %d received:", frame);
    for (i = 0; i < count; i++)
      printf(" %d", packet_ids[i]);
    printf("\n");

    for (i = 0; i < count; i++) {
      printf("Packet %d - ACK(0) or NAK(-1): ", packet_ids[i]);
      scanf("%d", &ack);
      sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&server, len);
    }

    frame++;
  }

  printf("All frames received successfully\nConnection closed\n");

  close(sockfd);
  return 0;
}
