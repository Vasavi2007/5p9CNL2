#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, k;
    int cost[10][10], dist[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;

            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    // Display routing tables
    for(i = 0; i < n; i++) {

        printf("\nRouting Table for Node %d:\n", i + 1);
        printf("Destination\tDistance\n");

        for(j = 0; j < n; j++) {
            printf("%d\t\t%d\n", j + 1, dist[i][j]);
        }
    }

    return 0;
}