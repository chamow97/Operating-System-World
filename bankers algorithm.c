#include<stdio.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void BankerAlorithm(int numberOfProcesses, int numberOfResources, int availableVector[100], int allocationMatrix[100][100], int needMatrix[100][100])
{
    /*----------------------------------------------------------------------------------------- */
    // initializations
    int isCompleted[numberOfProcesses];
    int i, j, remainingProcess = numberOfProcesses;

    for(i=0; i<numberOfProcesses; i++)
    {
        isCompleted[i] = FALSE;
    }
    /*----------------------------------------------------------------------------------------- */
    //Algorithm

    while(remainingProcess > 0)
    {
        for(i=0; i<numberOfProcesses; i++)
        {
            int temp = remainingProcess;
            //isHigher tells whether ith process is possible or not
            int isHigher = FALSE;
            //execute only when process i is not already completed
            if(isCompleted[i] == FALSE)
            {
                for(j=0; j<numberOfResources; j++)
                {
                    //condition for process i to execute
                    if(needMatrix[i][j] > availableVector[j])
                    {
                        isHigher = TRUE;
                        break;
                    }
                    else
                    {
                        isHigher = FALSE;

                    }
                }
                if(isHigher == TRUE)
                {
                    //skip this process
                }
                else
                {
                    for(j=0; j<numberOfResources; j++)
                    {
                        availableVector[j] += allocationMatrix[i][j];
                    }
                    --remainingProcess;
                    isCompleted[i] = TRUE;

                    printf("\n\n\t Process %d is Completed ! ", i+1);

                }
                //this means that no process has completed in this cycle and
                //hence it is not going to complete anyways
//                if(temp == remainingProcess && remainingProcess > 0)
//                {
//                    printf("\n\n\t System is in deadlock condition!!");
//                    return;
//                }
            }


        }
        /*----------------------------------------------------------------------------------------- */

        //checking for deadlock condition if time spent > 5sec assumed to be deadlock

        /*----------------------------------------------------------------------------------------- */



    }


}

int main()
{
    int numberOfResources, numberOfProcesses, availableVector[100], allocationMatrix[100][100], needMatrix[100][100], maximumMatrix[100][100];
    int i, j;
     /*----------------------------------------------------------------------------------------- */
     printf("\n\n\t BANKER'S ALGORITHM\n\t ------ - ---------");
     printf("\n\n\t");
     /*----------------------------------------------------------------------------------------- */
     //input section
     printf("\n\n\t Enter the number of processes : ");
     scanf("%d", &numberOfProcesses);
     printf("\n\n\t Enter number of resources : ");
     scanf("%d", &numberOfResources);

     printf("\n\n\t Enter the Max Matrix : \n");
     //maximum Matrix
     for(i=0; i<numberOfProcesses; i++)
     {
         for(j=0; j<numberOfResources; j++)
         {
             scanf("%d", &maximumMatrix[i][j]);
         }
     }
     printf("\n\n\t Enter the allocation Matrix : \n");
     //allocation matrix
     for(i=0; i<numberOfProcesses; i++)
     {
         for(j=0; j<numberOfResources; j++)
         {
             scanf("%d", &allocationMatrix[i][j]);
         }
     }
     printf("\n\n\t Enter the current Available resource vector: \n");
     //available vector
     for(i=0; i<numberOfResources; i++)
     {
         scanf("%d", &availableVector[i]);
     }

      /*----------------------------------------------------------------------------------------- */
     //calculating the need Matrix
    printf("\n\n\t Need Matrix : \n");
     for(i=0; i<numberOfProcesses; i++)
     {
        for(j=0; j<numberOfResources; j++)
        {
            needMatrix[i][j] = maximumMatrix[i][j] - allocationMatrix[i][j];
            printf("%d ", needMatrix[i][j]);
        }
        printf("\n");
     }
     printf("\n\n\t Order Of Process Completion : \n");
     BankerAlorithm(numberOfProcesses, numberOfResources, availableVector, allocationMatrix, needMatrix);


}
