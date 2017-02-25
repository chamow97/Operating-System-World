#include<stdio.h>


//a function to calculate maximum of 2 numbers

int max(int a, int b)
{
if(a >= b)
{
return a;
}

else
{
return b;
}
}


int main()
{
int i, n, arrivalTime[100], waitingTime[100], turnaroundTime[100], burstTime[100], totalWaitingTime = 0, totalTurnaroundTime = 0;
float avgWaitTime = 0.0, avgTurnaroundTime = 0.0;


printf("\n\n\t\t First Come First Serve Scheduling Algorithm!!\n\t\t ----- ---- ----- ----- ---------- ---------");
printf("\n\n\t Enter the number of processes : ");
scanf("%d", &n);
printf("\n\n\t Enter the Arrival Time followed by Burst Time(in msec) : \n\n");

for(i=0; i<n; i++)
{
waitingTime[i] = 0;
turnaroundTime[i] = 0;
}

//acceping the arrival and burst time
for(i=0; i<n; i++)
{
printf("\n\t Process %d :", i+1);
scanf("%d %d", &arrivalTime[i], &burstTime[i]);
}

//calculating for process 0
waitingTime[0] = arrivalTime[0];
turnaroundTime[0] = burstTime[0] + arrivalTime[0];
totalWaitingTime += waitingTime[0];
totalTurnaroundTime += (turnaroundTime[0]);


for(i=1; i<n; i++)
{

// if arrival time of i is greater than turnaround time of i-1, wait till the arrival time comes

waitingTime[i] = max(turnaroundTime[i-1], arrivalTime[i]);
turnaroundTime[i] = waitingTime[i] + burstTime[i];
totalWaitingTime += waitingTime[i];
totalTurnaroundTime += turnaroundTime[i];

}
//calculating the average . . . 
avgWaitTime = (totalWaitingTime * 1.0)/(n * 1.0);
avgTurnaroundTime = (totalTurnaroundTime * 1.0)/(n * 1.0);

printf("\n\n\t Average Waiting Time : %.2f", avgWaitTime);

printf("\n\n\t Average Turnaround Time : %.2f", avgTurnaroundTime);
return 0;
}
