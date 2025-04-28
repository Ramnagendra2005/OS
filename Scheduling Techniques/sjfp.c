#include <stdio.h>

int main() {
    int numberOfProcesses, burstTime[20], remainingTime[20], arrivalTime[20];
    int waitingTime[20], turnaroundTime[20], completionTime[20];
    int i, smallest, time = 0, endTime;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    int completed = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    // Input burst times and arrival times for each process
    printf("Enter the burst time and arrival time of each process:\n");
    for (i = 0; i < numberOfProcesses; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
        remainingTime[i] = burstTime[i];
    }

    printf("\nGantt Chart:\n");
    printf("|");

    // Process scheduling loop
    while (completed != numberOfProcesses) {
        smallest = -1;
        // Find the process with the smallest remaining time that has arrived
        for (i = 0; i < numberOfProcesses; i++) {
            if (remainingTime[i] > 0 && arrivalTime[i] <= time) {
                if (smallest == -1 || remainingTime[i] < remainingTime[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        // Print process in Gantt chart
        printf(" P%d |", smallest + 1);

        remainingTime[smallest]--;
        time++;

        // When process completes, update completion time, turnaround time, and waiting time
        if (remainingTime[smallest] == 0) {
            completed++;
            endTime = time;
            completionTime[smallest] = endTime;

            // Turnaround Time = Completion Time - Arrival Time
            turnaroundTime[smallest] = completionTime[smallest] - arrivalTime[smallest];

            // Waiting Time = Turnaround Time - Burst Time
            waitingTime[smallest] = turnaroundTime[smallest] - burstTime[smallest];
        }
    }

    // Display process details
    printf("\n\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < numberOfProcesses; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], arrivalTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / numberOfProcesses);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / numberOfProcesses);

    return 0;
}