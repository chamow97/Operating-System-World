#include<stdio.h>

struct set 
{
  int arrivalTime, burstTime, priorityOfProcess;
}S[100];

void bubbleSort(int n)
{
  int i,j;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n-1; j++ )
    {
      if(S[j].priorityOfProcess > S[j+1].priorityOfProcess)
      {
	struct set temp = S[j];
	S[j] = S[j+1];
	S[j+1] = temp;
      }
    }
  }
  
}


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


int * priorityScheduling(int n)
{
  //function variables
  int i;
  int waitingTime[n], turnaroundTime[n], totalTurnaroundTime = 0, totalWaitingTime = 0;
    
    
   //sorting the data on basis of priority
  bubbleSort(n);
  
   for(i=0; i<n; i++)
    {
	    waitingTime[i] = 0;	
	    turnaroundTime[i] = 0;
    }
    
    //calculating for process 0
    waitingTime[0] = S[i].arrivalTime;
    turnaroundTime[0] = S[i].burstTime + S[i].arrivalTime;
    totalWaitingTime += waitingTime[0];
    totalTurnaroundTime += (turnaroundTime[0]);


    for(i=1; i<n; i++)
    {

        // if arrival time of i is greater than turnaround time of i-1, wait till the arrival time comes

        waitingTime[i] = max(turnaroundTime[i-1], S[i].arrivalTime);
        turnaroundTime[i] = waitingTime[i] + S[i].burstTime;
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        
    }
    
    static int answerArray[2];
    answerArray[0] = totalWaitingTime;
    answerArray[1] = totalTurnaroundTime;
    
    //printf("%d %d", totalWaitingTime, totalTurnaroundTime);
    return answerArray;
  
}



int main()
{
  //variable declaration
  
  int i, n, waitingTime[100], turnaroundTime[100], totalWaitingTime = 0, totalTurnaroundTime = 0;
  float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0;
  int *answerArray;
  
  //struct set S[100];
  printf("\n\n\t\t Priority Based Scheduling!!\n\t\t -------- ----- ----------");
  printf("\n\n\t Enter number of processes : ");
  scanf("%d", &n);
  
  printf("\n\n\t Enter the Arrival Time, Burst Time and Priority(in msec) : \n\n");

  for(i=0; i<n; i++)
  {
    waitingTime[i] = 0;
    turnaroundTime[i] = 0;
  }

  //acceping the arrival and burst time and priority
  for(i=0; i<n; i++)
  {
    printf("\n\t Process %d :", i+1);
    scanf("%d %d %d", &S[i].arrivalTime, &S[i].burstTime, &S[i].priorityOfProcess); 
  }
  
  answerArray = priorityScheduling(n);
  averageWaitingTime = ((*(answerArray)) * (1.00))/(n * 1.00);
    averageTurnaroundTime = ((*(answerArray + 1)) * (1.00))/(n * 1.00);
    
    printf("\n\n\t Average Waiting Time : %.2f ms", averageWaitingTime);
    printf("\n\n\t Average Turnaround Time : %.2f ms", averageTurnaroundTime);

}