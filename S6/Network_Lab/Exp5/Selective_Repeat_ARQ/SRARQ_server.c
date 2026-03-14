#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, wsize, total, i, frame = 0, next = 0, count;
  int ack[100], pkt[100];
  struct sockaddr_in server, client;
  socklen_t len = sizeof(client);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server.sin_family = AF_INET;
  server.sin_port = htons(9000);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(sockfd, (struct sockaddr *)&server, sizeof(server));

  recvfrom(sockfd, &wsize, sizeof(wsize), 0, (struct sockaddr *)&client, &len);
  printf("Window Size Received: %d\n", wsize);

  printf("Enter Total Packets: ");
  scanf("%d", &total);
  sendto(sockfd, &total, sizeof(total), 0, (struct sockaddr *)&client, len);

  while (1) {
    int naks = 0;
    if (frame > 0)
      for (i = 0; i < count; i++)
        if (ack[i] == -1)
          pkt[naks++] = pkt[i];
    count = naks;

    while (count < wsize && next < total)
      pkt[count++] = next++;

    if (count == 0)
      break;

    printf("\nFrame %-3d packets :", frame);
    for (i = 0; i < count; i++)
      printf("%5d", pkt[i]);
    printf("\nSending Frame %-3d\n", frame);

    sendto(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&client, len);
    sendto(sockfd, pkt, sizeof(int) * count, 0, (struct sockaddr *)&client,
           len);
    recvfrom(sockfd, ack, sizeof(int) * count, 0, (struct sockaddr *)&client,
             &len);

    int error = 0;
    for (i = 0; i < count; i++)
      if (ack[i] == -1) {
        printf("NAK Received -> Packet %d\nRetransmitting Packet %d\n", pkt[i],
               pkt[i]);
        error = 1;
      }

    if (!error)
      printf("ACK Received -> All Packets\n");

    frame++;
    if (!error && next >= total)
      break;
  }

  count = 0;
  sendto(sockfd, &count, sizeof(count), 0, (struct sockaddr *)&client, len);
  printf("\nAll Frames Sent Successfully\nConnection Closed\n");

  close(sockfd);
  return 0;
}