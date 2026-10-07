#include <stdio.h>

int main() {
    int bucket_size, output_rate, n;
    int input, stored = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("\nEnter packets arriving at time %d: ", i);
        scanf("%d", &input);

        if(stored + input > bucket_size) {
            printf("Bucket overflow! %d packets dropped.\n",
                   stored + input - bucket_size);

            stored = bucket_size;
        } else {
            stored = stored + input;
        }

        if(stored >= output_rate) {
            printf("Packets transmitted: %d\n", output_rate);
            stored = stored - output_rate;
        } else {
            printf("Packets transmitted: %d\n", stored);
            stored = 0;
        }

        printf("Packets remaining in bucket: %d\n", stored);
    }

    return 0;
}