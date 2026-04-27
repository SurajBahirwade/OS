#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], wt[n], tat[n], done[n], pid[n];

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        pid[i] = i + 1;
        done[i] = 0;
    }

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter Priority (smaller number = higher priority):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    while(completed < n) {
        int idx = -1;
        int highest = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(pr[i] < highest) {
                    highest = pr[i];
                    idx = i;
                } else if(pr[i] == highest) {
                    if(at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
                   pid[idx], at[idx], bt[idx], pr[idx], ct[idx], tat[idx], wt[idx]);

            done[idx] = 1;
            completed++;
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
