#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, wsize, total_packets, i;
  int frame = 0, base = 0, count, ack;
  int packet_ids[100];
  struct sockaddr_in server, client;
  socklen_t len = sizeof(client);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9001);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sockfd, (struct sockaddr *)&server, sizeof(server));

  recvfrom(sockfd, &wsize, sizeof(wsize), 0, (struct sockaddr *)&client, &len);
  printf("Window Size Received: %d\n", wsize);

  printf("Enter Total Packets: ");
  scanf("%d", &total_packets);
  sendto(sockfd, &total_packets, sizeof(total_packets), 0,
         (struct sockaddr *)&client, len);

  while (base < total_packets) {
    count = 0;
    for (i = base; i < base + wsize && i < total_packets; i++) {
      packet_ids[count] = i;
      count++;
    }

    printf("\nFrame %-3d packets :", frame);
    for (i = 0; i < count; i++)
      printf("%5d", packet_ids[i]);
    printf("\nSending Frame %-3d\n", frame);

    sendto(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&client, len);
    sendto(sockfd, packet_ids, sizeof(int) * count, 0,
           (struct sockaddr *)&client, len);

    int nak_received = 0;
    for (i = 0; i < count; i++) {
      recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&client, &len);
      if (ack == -1) {
        printf("Packet %d -> NAK\n", packet_ids[i]);
        nak_received = 1;
      } else {
        printf("Packet %d -> ACK\n", packet_ids[i]);
      }
    }

    if (nak_received) {
      printf("NAK Received -> Retransmitting Frame %d\n", frame);
    } else {
      printf("All Packets ACK -> Frame %d Accepted\n", frame);
      base += count;
    }

    frame++;
  }

  count = 0;
  sendto(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&client, len);
  printf("\nAll Frames Sent Successfully\nConnection Closed\n");

  close(sockfd);
  return 0;
}
