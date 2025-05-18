#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int p[n]; // process IDs

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d - Arrival Time and Burst Time: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i; // Assign process ID
    }

    // Sort by Arrival Time (and by PID to maintain stable order if needed)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && p[i] > p[j])) {
                // Swap AT
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                // Swap BT
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap PID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Completion Time (CT)
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[i])
            current_time = at[i]; // CPU idle until process arrives
        current_time += bt[i];
        ct[i] = current_time;
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    double avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    // Print Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i] + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n ");

    // Top bar
    for (int i = 0; i < n; i++) {
        printf("----");
    }
    printf("-\n");

    // Process IDs
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("P%d |", p[i] + 1);
    }
    printf("\n ");

    // Bottom bar
    for (int i = 0; i < n; i++) {
        printf("----");
    }
    printf("-\n");

    // Time markers
    int start_time = (at[0] > 0) ? at[0] : 0;
    printf("%d", start_time);
    for (int i = 0; i < n; i++) {
        if (ct[i] < 10)
            printf("   %d", ct[i]);
        else
            printf("  %d", ct[i]);
    }

    // Averages
    printf("\n\nAverage Waiting Time = %.2lf", avg_wt);
    printf("\nAverage Turnaround Time = %.2lf\n", avg_tat);

    return 0;
}
