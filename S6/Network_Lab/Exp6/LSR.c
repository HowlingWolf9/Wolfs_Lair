#include <stdio.h>
#define MAX 20
#define INF 1000

int main() {
  int cost[MAX][MAX], dist[MAX], visited[MAX], nexthop[MAX];
  int n, i, j, src, min, u;

  printf("Enter the Number of Nodes : ");
  scanf("%d", &n);

  printf("Enter the cost between Nodes : \n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i != j) {
        printf("Cost from %d->%d : ", i, j);
        scanf("%d", &cost[i][j]);
        if (cost[i][j] == 0)
          cost[i][j] = INF;
      } else {
        cost[i][j] = 0;
      }
    }
  }

  printf("Enter the source Node : ");
  scanf("%d", &src);

  printf("\nRouting Table of Node %d\n", src);
  printf("Destination\tCost\tNext Hop\n");
  for (i = 1; i <= n; i++) {
    if (i == src)
      printf("  %d\t\t-\t\t-\n", i);
    else
      printf("  %d\t\t%d\t\t-\n", i, cost[src][i]);
  }

  for (i = 1; i <= n; i++) {
    dist[i] = cost[src][i];
    visited[i] = 0;
    nexthop[i] = (cost[src][i] != 0 && cost[src][i] != INF) ? i : 0;
  }
  dist[src] = 0;
  visited[src] = 1;

  for (i = 1; i < n; i++) {
    min = INF;
    u = -1;
    for (j = 1; j <= n; j++) {
      if (!visited[j] && dist[j] < min) {
        min = dist[j];
        u = j;
      }
    }
    if (u == -1)
      break;
    visited[u] = 1;
    for (j = 1; j <= n; j++) {
      if (!visited[j] && cost[u][j] != 0 && dist[u] + cost[u][j] < dist[j]) {
        dist[j] = dist[u] + cost[u][j];
        nexthop[j] = nexthop[u];
      }
    }
  }

  printf("\nAfter Applying Dijkstra's Algorithm\n");
  printf("\nRouting Table of Node %d \n", src);
  printf("Destination\tCost\tNext Hop \n");
  for (i = 1; i <= n; i++) {
    if (i == src)
      printf("  %d\t\t0\t\t-\n", i);
    else if (nexthop[i] == i)
      printf("  %d\t\t%d\t\t-\n", i, dist[i]);
    else
      printf("  %d\t\t%d\t\t%d\n", i, dist[i], nexthop[i]);
  }

  for (i = 1; i <= n; i++) {
    if (i != src)
      printf("\nThe cost of the shortest path from router %d to %d is %d", src,
             i, dist[i]);
  }
  printf("\n");

  return 0;
}
