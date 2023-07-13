#include <stdio.h>

int turnarroundtime(int processes[], int n,
int bt[], int wt[], int tat[]) {

   for (int i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}

int waitingtime(int processes[], int n,
int bt[], int wt[], int quantum) {

   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0;

   while (1) {
      int done = 1;

      for (int i = 0 ; i < n; i++) {

         if (rem_bt[i] > 0) {
            done = 0;
            if (rem_bt[i] > quantum) {

               t += quantum;

               rem_bt[i] -= quantum;
            }

            else {

               t = t + rem_bt[i];

               wt[i] = t - bt[i];

               rem_bt[i] = 0;
            }
         }
      }

      if (done == 1)
         break;
   }
   return 1;
}

int findavgTime(int processes[], int n, int bt[],
int quantum) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;

   waitingtime(processes, n, bt, wt, quantum);

   turnarroundtime(processes, n, bt, wt, tat);

   printf("Processes \t | Burst Time\t | Waiting Time \t| turnaround time\t");

   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1, bt[i], wt[i], tat[i]);
   }
   printf("\nAverage waiting time = %f", (float)total_wt / (float)n);
   printf("\nAverage turnaround time = %f", (float)total_tat / (float)n);
   return 1;
}

int main() {
        int n;
    printf("Enter the no.of process");
    scanf("%d",&n);
    int proc[n];
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
        proc[i] = i+1;
    }

    printf("Enter the burst time for each of the process ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst_time[i]);
    }
   int quantum;
    printf("Enter the quantum");
    scanf("%d",&quantum);
   findavgTime(proc, n, burst_time, quantum);
   return 0;
}
