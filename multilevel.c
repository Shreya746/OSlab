#include<stdio.h>
#include <stdlib.h>
struct process{
	int burst_time;
	int pid;
	int waiting_time;
	int turnaround_time;
	int arrival_time;
};
void getInput();
void calcWaitingTime(struct process *q,int);
void calcTurnAroundTime(struct process *q,int);
void printQueue(struct process *q,int size);
void FCFS();
void FCFSAlgorithm(struct process *q,int size);

int q1_n=0,q2_n=0,q3_n=0,n=0; //N=Total Process
struct process *q1,*q2,*q3;
void getInput(){
	printf("\n Total Number of Process:\t");
	scanf("%d",&n);
    struct process q1;
    struct process q2;
	// q1 = (struct process *)malloc(n*sizeof(struct process));
	// q2 = (struct process *)malloc(n*sizeof(struct process));
    int choice;
	for(int i=0;i<n;i++){
        printf("Enter which type of process is this 1.System processs or 2.User process?");
        scanf("%d",&choice);
		struct process p;
		printf("\n\t\tProcess %d\n=============================================\n\n",i+1);
		// p.arrival_time = (rand())%(n+1);				
		printf("PId:\t");
		scanf("%d",&p.pid);
		printf("\nBurst Time:");
		scanf("%d",&p.burst_time);
        switch (choice)
        {
        case 1:
            q1 =p;   
            q1_n++;
            break;
        case 2:
            q2 = p;
            q2_n++;
        default:

            break;
        
        }
}
}
void printQueue(struct process *q,int size){	
	calcWaitingTime(q,size);
	calcTurnAroundTime(q,size);
	printf("\nPId\t\tPriority\t\tBurst Time\t\tWaiting Time\t\tTurnAround Time\t\tArrival");
	printf("\n================================================================================\n");
	for(int i=0;i<size;i++){
		printQueueI(q[i]);
	}
	printf("\n\n");
}
void printQueueI(struct process p){
	printf("\n%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t",p.pid,p.burst_time,p.waiting_time,p.turnaround_time,p.arrival_time);
}
void calcWaitingTime(struct process *q,int size){
	q[0].waiting_time = 0;
	for(int i=1;i<size;i++){
		q[i].waiting_time = q[i-1].waiting_time + q[i-1].burst_time;
	}
}
void calcTurnAroundTime(struct process *q,int size){
	q[0].waiting_time = 0;
	for(int i=0;i<size;i++){
		q[i].turnaround_time = q[i].waiting_time + q[i].burst_time;
	}
}

void FCFSAlgorithm(struct process *q,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(q[j].arrival_time>q[i].arrival_time){
				struct process t = q[i];
				q[i] = q[j];
				q[j] = t;
			}
		}
	}
}
void FCFS(){
	printf("\n\n===========================================================================");
	printf("\n\t\tFirst Come First Serve\t");
	printf("\n===========================================================================\n\n");
	FCFSAlgorithm(q1,q1_n);
    FCFSAlgorithm(q2,q2_n);
    printf("System process FCFS Scheduling");
	printQueue(q1,q1_n);
    printf("User processs FCFS Scheduling");
    printQueue(q2,q2_n);
}
int main(){
	getInput();
    FCFS();

	printf("\n\n");
}