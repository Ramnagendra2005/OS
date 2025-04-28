#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int p[n]; // process id array

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i; // initial process id
    }

    // Sort by arrival time
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process id
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Completion Time (ct)
    int crnt = 0;
    for (int i = 0; i < n; i++) {
        if (crnt < at[i]) {
            crnt = at[i]; // CPU idle
        }
        crnt += bt[i];
        ct[i] = crnt;
    }

    // Calculate TAT and WT
    double avg_wt = 0;
    double avg_tat = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    // Display Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i]+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Display Gantt Chart
    printf("\nGantt Chart:\n");

    printf(" |");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");

    printf(" ");
    for (int i = 0; i < n; i++) {
        printf("P%d", p[i]+1);
        for (int j = 0; j < bt[i]-1; j++) {
            printf(" ");
        }
        printf(" ");
    }
    printf("\n");

    printf(" |");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");

    printf("%d", (at[0] > 0) ? at[0] : 0);
    int temp = (at[0] > 0) ? at[0] : 0;
    for (int i = 0; i < n; i++) {
        temp = (temp > at[i]) ? temp : at[i];
        temp += bt[i];
        printf("\t%d", temp);
    }

    printf("\n\nAverage Waiting Time = %.2lf", avg_wt);
    printf("\nAverage Turnaround Time = %.2lf\n", avg_tat);

    return 0;
}