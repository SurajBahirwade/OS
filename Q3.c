#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    int completed = 0, flag;

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    while(completed < n) {
        flag = 0;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {
                flag = 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                           i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

                    completed++;
                }
            }
        }

        if(flag == 0) {
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
