#include <stdio.h>
#define INF 999

int main() {
    int n, g[10][10], d[10], v[10] = {0};
    int i, j, min, u, s;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&g[i][j]);
            if(g[i][j]==0 && i!=j) g[i][j]=INF;
        }

    printf("Enter source: ");
    scanf("%d",&s);

    for(i=0;i<n;i++) d[i]=g[s][i];
    d[s]=0;

    for(i=0;i<n-1;i++) {
        min=INF;
        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min)
                min=d[j],u=j;

        v[u]=1;

        for(j=0;j<n;j++)
            if(!v[j] && d[u]+g[u][j]<d[j])
                d[j]=d[u]+g[u][j];
    }

    printf("Shortest distances:\n");
    for(i=0;i<n;i++)
        printf("%d -> %d = %d\n",s,i,d[i]);

    return 0;
}