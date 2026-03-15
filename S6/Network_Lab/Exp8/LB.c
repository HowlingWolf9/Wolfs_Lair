#include <stdio.h>

int main() {
  int bucket_size, outflow_rate, num_packets;
  int buffer = 0, packet_size, dropped, sent, i;

  printf("Enter the bucket size (Bytes): ");
  scanf("%d", &bucket_size);

  printf("Enter the outgoing rate (Bytes per second): ");
  scanf("%d", &outflow_rate);

  printf("Enter the no of packets: ");
  scanf("%d", &num_packets);

  for (i = 0; i < num_packets; i++) {
    printf("\nEnter the incoming packet size (Bytes): ");
    scanf("%d", &packet_size);

    if (buffer + packet_size > bucket_size) {
      dropped = buffer + packet_size - bucket_size;
      printf("Dropped %d bytes of data from the packet\n", dropped);
      buffer = bucket_size;
    } else {
      buffer += packet_size;
    }

    printf("Current Bucket buffer size %d out of %d\n", buffer, bucket_size);

    sent = (buffer < outflow_rate) ? buffer : outflow_rate;
    buffer -= sent;

    printf("After outgoing %d bytes are left out of %d in the buffer\n", buffer,
           bucket_size);
  }

  if (buffer > 0) {
    printf("\n--- No more incoming packets. Emptying remaining buffer ---\n");
  }

  while (buffer > 0) {
    sent = (buffer < outflow_rate) ? buffer : outflow_rate;
    buffer -= sent;
    printf("After outgoing %d bytes are left out of %d in the buffer\n", buffer,
           bucket_size);
  }

  return 0;
}