#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], ct[20], pid[20];
    int i, j, time = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time, priority, and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign process IDs starting from 1
        printf("Process %d\n", pid[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }

    // Sort based on priority (ascending order), and arrival time if needed
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            // If priority same, sort by arrival time to maintain FCFS within same priority
            if (pr[i] > pr[j] || (pr[i] == pr[j] && at[i] > at[j])) {
                int temp;
                // Swap priority
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap arrival time
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                // Swap process IDs
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Calculate Completion, Waiting, Turnaround Times
    time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i]) time = at[i]; // CPU idle if process not arrived
        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    // Display process info
    printf("\nProcess\tBurst Time\tPriority\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               pid[i], bt[i], pr[i], at[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Simple Gantt Chart Printing
    printf("\nGantt Chart:\n ");

    // Top bar
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    // Process IDs centered under bars
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", pid[i]);
        for (j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    // Bottom bar
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    // Time line below bars
    int current_time = (at[0] > 0) ? at[0] : 0;
    printf("%d", current_time);
    for (i = 0; i < n; i++) {
        current_time = (current_time > at[i]) ? current_time : at[i];
        current_time += bt[i];
        if (current_time < 10)
            printf("  %d", current_time);
        else
            printf(" %d", current_time);
    }
    printf("\n");

    return 0;
}
