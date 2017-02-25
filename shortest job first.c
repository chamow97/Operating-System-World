#include <stdio.h>


void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
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



void bubbleSort(int burstTime[], int arrivalTime[], int n)
{
    int i,j;
    int temp1, temp2; //to swap during sorting
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(burstTime[j] > burstTime[j+1])
            {
                swap(&arrivalTime[j], &arrivalTime[j+1]);
                swap(&burstTime[j], &burstTime[j+1]);
            }
        }
    }
    
    for(i=0; i<n; i++)
    {
       //printf("%d\n",arrivalTime[i]);
    }
    
}


int * sjfScheduling(int burstTime[], int arrivalTime[] , int n)
{
    
    int waitingTime[n], turnaroundTime[n], totalTurnaroundTime = 0, totalWaitingTime = 0;
    
    int i,j; //loop variables
    
    //sorting the data on basis of arrivalTime
    
    bubbleSort(burstTime, arrivalTime, n);
    
     
    for(i=0; i<n; i++)
    {
	    waitingTime[i] = 0;	
	    turnaroundTime[i] = 0;
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
    
    static int answerArray[2];
    answerArray[0] = totalWaitingTime;
    answerArray[1] = totalTurnaroundTime;
    
    //printf("%d %d", totalWaitingTime, totalTurnaroundTime);
    return answerArray;
    
}


int main()
{
    //variable declaration
    int n, burstTime[100], arrivalTime[100];
    int *answerArray;
    float averageTurnaroundTime = 0.00, averageWaitingTime = 0.0;
    int i,j; // loop var
    
    
    
    printf("\n\n\t Shortest Job First Scheduling Algorithm. \n\t -------- --- ----- ---------- ---------");
    printf("\n\n\t Enter number of Jobs : ");
    scanf("%d", &n);
    printf("\n\n\t Enter the Burst Time followed by Arrival Time of %d processes : (in msec)",n);
    
    for(i=0; i<n; i++)
    {
        scanf("%d%d", &burstTime[i], &arrivalTime[i]);
    }
    
    //sorting the process using arrival Time 
    answerArray = sjfScheduling(burstTime, arrivalTime, n);
    
    averageWaitingTime = ((*(answerArray)) * (1.00))/(n * 1.00);
    averageTurnaroundTime = ((*(answerArray + 1)) * (1.00))/(n * 1.00);
    
    printf("\n\n\t Average Waiting Time : %.2f ms", averageWaitingTime);
    printf("\n\n\t Average Turnaround Time : %.2f ms", averageTurnaroundTime);
    
    return 0;
}

