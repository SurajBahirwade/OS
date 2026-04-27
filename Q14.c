#include <stdio.h>

int main() {
    int n, i, head, total = 0, completed = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    while(completed < n) {
        int min = 99999, idx = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                int diff = head - req[i];
                if(diff < 0)
                    diff = -diff;

                if(diff < min) {
                    min = diff;
                    idx = i;
                }
            }
        }

        visited[idx] = 1;
        total += min;
        head = req[idx];

        printf("-> %d ", head);

        completed++;
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}
