#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], rem_bt[20], ct[20];
    int i, time = 0, completed = 0, prev = -1;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    printf("Enter the priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    printf("\nGantt Chart:\n|");

    // Preemptive Priority Scheduling
    while (completed < n) {
        int min_priority = 1000000, proc_index = -1;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= time && pr[i] < min_priority) {
                min_priority = pr[i];
                proc_index = i;
            }
        }

        if (proc_index == -1) {
            time++; // CPU Idle
            continue;
        }

        if (prev != proc_index) {
            printf(" P%d |", proc_index + 1); // Print only when process changes
            prev = proc_index;
        }

        rem_bt[proc_index]--;
        time++;

        if (rem_bt[proc_index] == 0) {
            completed++;
            ct[proc_index] = time; // Completion time
        }
    }

    printf("\n");

    // Now calculate WT and TAT
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];          // TAT = Completion - Arrival
        wt[i] = tat[i] - bt[i];           // WT = TAT - Burst
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], pr[i], ct[i], wt[i], tat[i]);
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    return 0;
}