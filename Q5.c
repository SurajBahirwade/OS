#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    while(completed < n) {
        int idx = -1;
        int min = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] < min) {
                    min = rt[i];
                    idx = i;
                } else if(rt[i] == min) {
                    if(at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                       idx+1, at[idx], bt[idx], ct[idx], tat[idx], wt[idx]);

                completed++;
            }
        } else {
            time++;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
