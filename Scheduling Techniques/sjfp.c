#include <stdio.h>

int main() {
    int n, bt[20], rt[20], at[20];
    int wt[20], tat[20], ct[20];
    int i, currentTime = 0, completed = 0, minIndex;
    float totalWT = 0, totalTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        rt[i] = bt[i]; // Initialize remaining time
    }

    printf("\nGantt Chart:\n|");

    while (completed != n) {
        minIndex = -1;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= currentTime) {
                if (minIndex == -1 || rt[i] < rt[minIndex]) {
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        printf(" P%d |", minIndex + 1);

        rt[minIndex]--;
        currentTime++;

        if (rt[minIndex] == 0) {
            completed++;
            ct[minIndex] = currentTime;
            tat[minIndex] = ct[minIndex] - at[minIndex];
            wt[minIndex] = tat[minIndex] - bt[minIndex];
            totalWT += wt[minIndex];
            totalTAT += tat[minIndex];
        }
    }

    printf("\n\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}