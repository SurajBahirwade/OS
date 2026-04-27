#include <stdio.h>

int main() {
    int n, f, i, j, k, pages[100], frame[50];
    int faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1;

            for(j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                int farthest = -1, index = -1;

                for(j = 0; j < f; j++) {
                    int next = -1;

                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    if(next > farthest) {
                        farthest = next;
                        index = j;
                    }
                }

                if(pos == -1) {
                    pos = index;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }

        printf("Frames: ");
        for(k = 0; k < f; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
