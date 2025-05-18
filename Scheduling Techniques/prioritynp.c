#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], ct[20], pid[20];
    int i, j, time = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time, priority, and arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d\n", pid[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Sort by priority (ascending), then arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j] || (pr[i] == pr[j] && at[i] > at[j])) {
                int temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Calculate CT, TAT, WT
    time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nProcess\tBT\tPr\tAT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], pr[i], at[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n\n", avgtat);

    // Simple Gantt Chart (minimalist)
    printf("Gantt Chart:\n");
    for (i = 0; i < n; i++) printf("| P%d ", pid[i]);
    printf("|\n");

    printf("0");
    int curr = (at[0] > 0) ? at[0] : 0;
    for (i = 0; i < n; i++) {
        if (curr < at[i]) curr = at[i];
        curr += bt[i];
        printf("   %d", curr);
    }
    printf("\n");

    return 0;
}
