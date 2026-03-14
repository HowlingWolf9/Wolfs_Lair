#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, total, i, ack, frame = 0;
  struct sockaddr_in server, client;
  socklen_t len = sizeof(client);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(sockfd, (struct sockaddr *)&server, sizeof(server));

  printf("Enter Total Packets: ");
  scanf("%d", &total);

  recvfrom(sockfd, &i, sizeof(i), 0, (struct sockaddr *)&client, &len);
  sendto(sockfd, &total, sizeof(total), 0, (struct sockaddr *)&client, len);

  for (i = 0; i < total; i++) {
    do {
      printf("\nFrame %-3d Packet : %d\n", frame, i);
      printf("Sending Frame %-3d\n", frame);

      sendto(sockfd, &i, sizeof(i), 0, (struct sockaddr *)&client, len);
      recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&client, &len);

      if (ack == -1) {
        printf("NAK Received -> Packet %d\nRetransmitting Packet %d\n", i, i);
      } else {
        printf("ACK Received -> Packet %d\n", i);
        frame++;
      }
    } while (ack == -1);
  }

  i = -1;
  sendto(sockfd, &i, sizeof(i), 0, (struct sockaddr *)&client, len);
  printf("\nAll Frames Sent Successfully\nConnection Closed\n");

  close(sockfd);
  return 0;
}