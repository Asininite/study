#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} Process;

void calculate_times(Process processes[], int n) {
    int time = 0, completed = 0;
    
    while (completed < n) {
        int shortest_index = -1;
        int shortest_burst = __INT_MAX__;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && !processes[i].completed && processes[i].burst_time < shortest_burst) {
                shortest_burst = processes[i].burst_time;
                shortest_index = i;
            }
        }
        
        if (shortest_index != -1) {
            time += processes[shortest_index].burst_time;
            processes[shortest_index].turnaround_time = time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
            processes[shortest_index].completed = true;
            completed++;
        } else {
            time++;
        }
    }
}

void print_processes(Process processes[], int n) {
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", 
               processes[i].id, 
               processes[i].arrival_time, 
               processes[i].burst_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].completed = false;
    }

    calculate_times(processes, n);
    print_processes(processes, n);

    return 0;
}
