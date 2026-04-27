#include <stdio.h>

int main() {
    int n, f, i, j, k, pages[100], frame[50], time[50];
    int count = 0, faults = 0;

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
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                count++;
                time[j] = count;
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
                int min = time[0];
                pos = 0;
                for(j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
            }

            count++;
            frame[pos] = pages[i];
            time[pos] = count;
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
