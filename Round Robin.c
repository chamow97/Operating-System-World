#include<stdio.h>

#define TRUE 1
#define FALSE 0

int min(int a, int b)
{
    if(a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

float * RoundRobin(int numberOfProcess, int arrivalTime[], int burstTime[], int timeSlice)
{
    int waitingTime[numberOfProcess], turnaroundTime[numberOfProcess], extraTime[numberOfProcess], remainingProcess;
    int flag = TRUE;
    int currentTime = 0;

    int i,j;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0, answerArray[2];


    /*----------------------------------------------------------------------------------------- */
    for(i=0; i<numberOfProcess; i++)
    {
        waitingTime[i] = 0;
        turnaroundTime[i] = 0;
        extraTime[i] = 0;
    }

    /*----------------------------------------------------------------------------------------- */
    //algorithm for RR
    remainingProcess = numberOfProcess;

    waitingTime[0] = arrivalTime[0];
    currentTime += waitingTime[0];

    //do till no remaining process
    while(flag == TRUE)
    {
        for(i=0; i<numberOfProcess; i++)
        {
            //if process is already over
            if(burstTime[i] == 0)
            {
                continue;

            }
            //if arrivalTime is greater than currentTime
            if(currentTime < arrivalTime[i])
            {
                int temp = currentTime;
                extraTime[i] += (arrivalTime[i] - temp);
                currentTime += (arrivalTime[i] - temp);
            }
            //if process can finish in this cycle
            if(burstTime[i] <= timeSlice)
            {
                waitingTime[i] = currentTime;
                waitingTime[i] += extraTime[i];
                turnaroundTime[i] = waitingTime[i];
                turnaroundTime[i] += burstTime[i];
                --remainingProcess; // a process finishes
                currentTime += (min(burstTime[i], timeSlice)); //to save CPU cycles
                burstTime[i] = 0;
            }
            else if(burstTime[i] > timeSlice)
            {
                burstTime[i] -= timeSlice;
                currentTime += timeSlice;
                waitingTime[i] = currentTime;

            }
            if(remainingProcess == 0)
            {
                flag = FALSE;
            }
        }

    }

    /*----------------------------------------------------------------------------------------- */
    //calculating the reqd values
    for(i=0; i<numberOfProcess; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    averageWaitingTime = (1.0 * totalWaitingTime)/(numberOfProcess * 1.0);

    averageTurnaroundTime = (1.0 * totalTurnaroundTime)/(numberOfProcess * 1.0);

    answerArray[0] = averageWaitingTime;
    answerArray[1] = averageTurnaroundTime;

    /*----------------------------------------------------------------------------------------- */

    return answerArray;

}

int main()
{
    int numberOfProcess, timeSlice;
    int i,j;
    float *answerArray;

    /*----------------------------------------------------------------------------------------- */

    //Input Section

    printf("\n\n\t Round Robin Scheduling Algorithm\n\t ----- ----- ----------- ---------");
    printf("\n\n\t Enter number of Processes : ");
    scanf("%d", &numberOfProcess);

    /*----------------------------------------------------------------------------------------- */

    int burstTime[100], arrivalTime[100];

    /*----------------------------------------------------------------------------------------- */
    //input continues

    printf("\n\n\t Enter the Arrival Time and Burst Time : \n");

    for(i=0; i<numberOfProcess; i++)
    {
        printf("\n\t Process %d : ", i+1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }
    printf("\n\t Enter the time slice : ");
    scanf("%d", &timeSlice);

    /*----------------------------------------------------------------------------------------- */

    //calling function Round Robin to calculate

    answerArray = RoundRobin(numberOfProcess, arrivalTime, burstTime, timeSlice);
    printf("\n\n\t Average Waiting Time : %f ms \n\n\t Average Turnaround Time : %f ms", *(answerArray),*(answerArray + 1));
    printf("\n\n");
}
