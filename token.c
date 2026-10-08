#include <stdio.h>

int main() {
    int bucket, rate, n, packet, tokens = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter token rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter packet size: ");
        scanf("%d", &packet);

        tokens += rate;
        if (tokens > bucket)
            tokens = bucket;

        if (packet <= tokens) {
            tokens -= packet;
            printf("Packet transmitted\n");
        } else {
            printf("Packet dropped\n");
        }
    }

    return 0;
}