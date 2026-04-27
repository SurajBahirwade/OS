#include <stdio.h>

int main() {
    int n, i, j, head, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int pos = 0;
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    for(i = pos; i < n; i++) {
        int diff = head - req[i];
        if(diff < 0)
            diff = -diff;

        total += diff;
        head = req[i];
        printf("-> %d ", head);
    }

    for(i = pos - 1; i >= 0; i--) {
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
