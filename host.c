#include <stdio.h>

int main() {
    int n, a[10][10], visited[10] = {0};
    int q[10], front = 0, rear = 0, i, j;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    visited[0] = 1;
    q[rear++] = 0;

    printf("Broadcast Tree:\n");

    while(front < rear) {
        int u = q[front++];

        for(i=0;i<n;i++) {
            if(a[u][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
                printf("%d -> %d\n", u, i);
            }
        }
    }

    return 0;
}