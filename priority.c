#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;       // Process ID
    int burst;     // Burst time
    int priority;  // Priority (lower number means higher priority)
    int arrival;   // Arrival time
    int wait;      // Waiting time
    int turn;      // Turnaround time
    int start;     // Start time
    int finish;    // Finish time
} Process;

// Function to swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes based on arrival time and priority using Bubble Sort
void sortProcesses(Process processes[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processes[j].arrival > processes[j+1].arrival || 
               (processes[j].arrival == processes[j+1].arrival && processes[j].priority > processes[j+1].priority)) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

// Function to calculate waiting and turnaround times
void calculateTimes(Process processes[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival) {
            currentTime = processes[i].arrival;  // Idle time in CPU
        }
        processes[i].start = currentTime;
        processes[i].wait = currentTime - processes[i].arrival;
        processes[i].finish = currentTime + processes[i].burst;
        processes[i].turn = processes[i].finish - processes[i].arrival;
        currentTime = processes[i].finish;
    }
}

// Function to display the Gantt chart
void displayGanttChart(Process processes[], int n) {
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++) {
        printf(" P%d ", processes[i].pid);
        if (i != n - 1) printf("|");
    }
    printf("\n");

    int currentTime = 0;
    printf("%d", currentTime);
    for (int i = 0; i < n; i++) {
        currentTime = processes[i].finish;
        printf("    %d", currentTime);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process P%d: ", i+1);
        processes[i].pid = i+1;
        scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }

    // Sort processes by arrival time and priority
    sortProcesses(processes, n);

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Display process information
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].priority, processes[i].wait, processes[i].turn);
    }

    // Display Gantt chart
    displayGanttChart(processes, n);

    return 0;
}
