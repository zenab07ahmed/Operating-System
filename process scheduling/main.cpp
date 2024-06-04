/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Process{
    string name;
    int BT;
    int WT;
    int TAT;
};

int main(){
    int numProcesses;
    cout<<"Ënter the number of processes";
    cin>>numProcesses;
    
    vector<Process>processes(numProcesses);
    
    for(int i=0;i<numProcesses;i++){
        cout<<"Ënter Burst time for process"<<(i+1) <<":";
        cin>>processes[i].BT;
        processes[i].name="P" +to_string(i+1);
        processes[i].WT=0;
        processes[i].TAT=0;
    }
    for(int i=1;i<numProcesses;i++){
        processes[i].WT=processes[i-1].WT+processes[i-1].BT;
        processes[i].TAT=processes[i].WT+processes[i].BT;
    }
    double avgWT=0,avgTAT=0;
    for(Process&process:processes){
        avgWT+=process.WT;
        avgTAT+=process.TAT;
    }
    avgWT/=numProcesses;
    avgTAT/=numProcesses;
    
    cout<<avgWT<<endl;
    cout<<avgTAT<<endl;
    }