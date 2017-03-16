#include<stdio.h>
int main()
{
    /*----------------------------------------------------------------------------------------- */
    //declare and initialize the values
    int inputBuffer[10000], bufferSize, dataIn, dataOut, toProduce, choice, toConsume;
    dataIn = 0;
    dataOut = 0;
    /*----------------------------------------------------------------------------------------- */
    //input
    printf("\n\n\t\t PRODUCER CONSUMER PROBLEM!!\n\n\t\t -------- -------- -------");
    printf("\n\n\t Enter the Buffer size : ");
    scanf("%d", &bufferSize);
    ++bufferSize;
    while(1)
    {
       printf("\n\n\t Enter the operation to perform : \n\t 1. Produce\n\t 2.Consume\n\t 3.Exit\n\t Enter your choice : ");
       scanf("%d", &choice);
       /*----------------------------------------------------------------------------------------- */
        //algorithm
       switch(choice)
       {
       case 1:
           if((dataIn+1) % (bufferSize) == dataOut)
           {
               printf("\n\t Buffer is Full!!");
           }
           else
           {
               printf("\n\t Enter value to produce : ");
               scanf("%d", &toProduce);
               inputBuffer[dataIn] = toProduce;
               dataIn = (dataIn + 1) % (bufferSize);
           }
           break;
       case 2:
            if(dataIn == dataOut)
            {
                printf("\n\t Buffer is Empty!!");
            }
            else
            {
                toConsume = inputBuffer[dataOut];
                printf("\n\t %d is Consumed!!", toConsume);
                dataOut = (dataOut + 1) % (bufferSize);
            }
            break;
       case 3:
            exit(1);
            break;
       default:
            printf("\n\n\t Invalid Choice!!!");
       }
    }



}
