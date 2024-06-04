#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int AT; // Arrival Time
    int BT; // Burst Time
    int WT; // Waiting Time
    int TAT; // Turnaround Time
};

bool compareArrivalTime(const Process& a, const Process& b) {
    return a.AT < b.AT;
}

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);

    // Input burst time and arrival time, and initialize process name
    for(int i = 0; i < numProcesses; i++) {
        cout << "Enter Arrival time for process " << (i + 1) << ": ";
        cin >> processes[i].AT;
        cout << "Enter Burst time for process " << (i + 1) << ": ";
        cin >> processes[i].BT;
        processes[i].name = "P" + to_string(i + 1);
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), compareArrivalTime);

    // Calculate waiting time and turnaround time
    int currentTime = 0;
    for(int i = 0; i < numProcesses; i++) {
        if (currentTime < processes[i].AT) {
            currentTime = processes[i].AT;
        }
        processes[i].WT = currentTime - processes[i].AT;
        processes[i].TAT = processes[i].WT + processes[i].BT;
        currentTime += processes[i].BT;
    }

    // Calculate average waiting time and average turnaround time
    double avgWT = 0, avgTAT = 0;
    for(const Process& process : processes) {
        avgWT += process.WT;
        avgTAT += process.TAT;
    }
    avgWT /= numProcesses;
    avgTAT /= numProcesses;

    // Output individual waiting time and turnaround time
    for(const Process& process : processes) {
        cout << "Process " << process.name << ": WT = " << process.WT << ", TAT = " << process.TAT << endl;
    }

    // Output average waiting time and average turnaround time
    cout << "Average WT: " << avgWT << endl;
    cout << "Average TAT: " << avgTAT << endl;

    return 0;
}
