#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], pr[20], at[20], rem_bt[20], i, j, time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;
    
    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and arrival time for each process
    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst times
    }

    // Input priority for each process
    printf("Enter the priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Preemptive priority scheduling algorithm
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");

    while (completed < n) {
        int min_priority = 1000000, proc_index = -1;

        // Find the process with the highest priority that has arrived
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= time && pr[i] < min_priority) {
                min_priority = pr[i];
                proc_index = i;
            }
        }

        // If no process is found (all processes arrived and completed), break the loop
        if (proc_index == -1) {
            time++;
            continue;
        }

        // Execute the selected process for 1 unit time
        rem_bt[proc_index]--;
        time++;

        // If process is completed, calculate waiting and turnaround times
        if (rem_bt[proc_index] == 0) {
            completed++;
            tat[proc_index] = time - at[proc_index]; // Turnaround time = Completion time - Arrival time
            wt[proc_index] = tat[proc_index] - bt[proc_index]; // Waiting time = Turnaround time - Burst time
            avgwt += wt[proc_index];
            avgtat += tat[proc_index];
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc_index + 1, bt[proc_index], at[proc_index], pr[proc_index], wt[proc_index], tat[proc_index]);
        }
    }

    // Calculate and display average waiting time and average turnaround time
    avgwt /= n;
    avgtat /= n;
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Gantt Chart
    printf("\nGantt Chart:\n");
    time = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for (i = 0; i < n; i++) {
        printf("P%d", i + 1); // Process display
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < bt[i]; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    // Display completion times in the Gantt chart
    printf("0");
    int time_counter = 0;
    for (i = 0; i < n; i++) {
        time_counter += bt[i];
        printf("  %d", time_counter);  // Aligning times
    }
    printf("\n");

    return 0;
}