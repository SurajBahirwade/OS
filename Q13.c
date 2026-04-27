#include <stdio.h>

int main() {
    int n, i, head, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++) {
        int diff = head - req[i];
        if(diff < 0)
            diff = -diff;

        total += diff;
        head = req[i];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}
