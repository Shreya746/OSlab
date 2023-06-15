#include<stdio.h>
#include<conio.h>

void waittime(int proc[], int n, int burst_time[], int wait_time[])
{
    wait_time[0] = 0;
    for(int i=1;i<n;i++)
    {
        wait_time[i] =  wait_time[i-1]+burst_time[i-1];
    }
}

void turnaroundtime(int proc[], int n, int burst_time[], int wait_time[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i] =  wait_time[i]+burst_time[i];
    }
}

void avgtime(int proc[], int n, int burst_time[])
{
    int wait_time[n];
    int tat[n];
    int total_wt = 0, total_tat = 0;
    waittime(proc,n,burst_time,wait_time);
    turnaroundtime(proc,n,burst_time,wait_time,tat);
    printf("process no | burst time | wait time | turn around time\n");
    for(int i=0;i<n;i++)
    {
        total_wt+=wait_time[i];
        total_tat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i],burst_time[i],wait_time[i],tat[i]);
    }
    double avgwt = (float)total_wt/n;
    printf("\nAverage wait time : %f",avgwt);
    double avgtat = (float)total_tat/n;
    printf("\nAverage turn around time: %f",avgtat);

}
void main()
{
    int n;
    printf("Enter the no.of process");
    scanf("%d",&n);
    int proc[n];
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
        proc[i] = i+1;
    }

    printf("Enter the burst time for each of them ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst_time[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(burst_time[i]>burst_time[j])
            {
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                int t = proc[i];
                proc[i]= proc[j];
                proc[j] = t;
            }
        }
    }
    avgtime(proc,n,burst_time);

}


