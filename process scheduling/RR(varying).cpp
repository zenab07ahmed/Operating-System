#include <iostream>
#include <vector>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum, int arrival[]) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0; // Current time
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && arrival[i] <= t) {
                done = false;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - arrival[i];
                    rem_bt[i] = 0;
                }
            }
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[], int arrival[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i] + arrival[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum, int arrival[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, quantum, arrival);

    findTurnAroundTime(processes, n, bt, wt, tat, arrival);

    cout << "Processes\tBurst time\tWaiting time\tTurn around time\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / n;
    cout << "\nAverage turn around time = " << (float)total_tat / n;
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8};

    int arrival_time[] = {0, 2, 4}; // Arrival times for each process

    int quantum = 2;
    findavgTime(processes, n, burst_time, quantum, arrival_time);
    return 0;
}
