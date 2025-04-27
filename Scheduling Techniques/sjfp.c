#include <stdio.h>

int main() {
    int numberOfProcesses, burstTime[20], remainingTime[20];
    int waitingTime[20], turnaroundTime[20];
    int i, smallest, time = 0, endTime;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    int completed = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < numberOfProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    printf("\nGantt Chart:\n");
    printf("|");

    while (completed != numberOfProcesses) {
        smallest = -1;
        for (i = 0; i < numberOfProcesses; i++) {
            if (remainingTime[i] > 0) {
                if (smallest == -1 || remainingTime[i] < remainingTime[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        printf(" P%d |", smallest + 1);

        remainingTime[smallest]--;
        time++;

        if (remainingTime[smallest] == 0) {
            completed++;
            endTime = time;
            turnaroundTime[smallest] = endTime;
            waitingTime[smallest] = turnaroundTime[smallest] - burstTime[smallest];
        }
    }

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < numberOfProcesses; i++) {
        turnaroundTime[i] = turnaroundTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / numberOfProcesses);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / numberOfProcesses);

    return 0;
}
