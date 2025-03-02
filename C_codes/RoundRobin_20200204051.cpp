#include<iostream>
using namespace std;


void findWaitingTime(int processes[], int n, int BT[], int WT[], int timeQuantum) {
    int rem_BT[n];
    for (int i = 0; i < n; i++)
        rem_BT[i] = BT[i];
    int t = 0;


    while (1) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (rem_BT[i] > 0) {
                done = false;

                if (rem_BT[i] > timeQuantum) {
                    t += timeQuantum;
                    rem_BT[i] -= timeQuantum;
                } else {
                    t += rem_BT[i];
                    WT[i] = t - BT[i];
                    rem_BT[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}


void findTurnAroundTime(int processes[], int n, int BT[], int WT[], int TAT[]) {
    for (int i = 0; i < n; i++)
        TAT[i] = BT[i] + WT[i];
}


void findavgTime(int processes[], int n, int BT[], int timeQuantum) {
    int WT[n], TAT[n], total_WT = 0, total_TAT = 0;

    findWaitingTime(processes, n, BT, WT, timeQuantum);
    findTurnAroundTime(processes, n, BT, WT, TAT);

    cout << "PN\t " << "\tBT " << "\t WT " << " \t\tTAT\n";

    for (int i = 0; i < n; i++) {
        total_WT = total_WT + WT[i];
        total_TAT = total_TAT + TAT[i];
        cout << " " << i+1 << "\t\t" << BT[i] << "\t " << WT[i] << "\t\t " << TAT[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_WT / (float)n;
    cout << "\nAverage turn around time = " << (float)total_TAT / (float)n;
}


int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {12, 7, 8, 4};
    int timeQuantum = 3;

    findavgTime(processes, n, burst_time, timeQuantum);
    return 0;
}
