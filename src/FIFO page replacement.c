#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0


int main()
{
	/*-------------------------------------------------------------------------------------*/
    //declaration section

    int i, j; //loop variables
	int numberOfFrames;
	int isAvailable[10]; //to store whether ith element is present.
	char referenceString[1000];
	int missCount = 0, hitCount = 0, currentPosition = 0;

	/*-------------------------------------------------------------------------------------*/
    //input section

    printf("\n\n\t\t FIFO Page Replacement Algorithm!\n\t\t ---- ---- ----------- ---------");
    printf("\n\n\t Enter the number of Frames : ");
    scanf("%d", &numberOfFrames);
    printf("\n\n\t Enter the reference String : ");
    scanf("%s", &referenceString);

    /*-------------------------------------------------------------------------------------*/
    //some initialisations

    int frame[numberOfFrames];
    int length = strlen(referenceString);

    for(i=0; i<numberOfFrames; i++)
    {
    	frame[i] = -1;
    }

    for(i=0; i<10; i++)
    {
    	isAvailable[i] = FALSE;
    }

    /*-------------------------------------------------------------------------------------*/
    //FIFO Algorithm

    currentPosition = 0;
    //initially fill the frame

    /* fill the frames if page is not available, if the page is available in frame, do not add again
    	isAvailable tells whether the ith page is present or not*/

    for(i=0; i<length; i++)
    {
    	if(currentPosition == numberOfFrames)
    	{
    		currentPosition = 0;
    	}

    	if(frame[currentPosition] == -1)
    	{
    		if(isAvailable[referenceString[i] - '0'] == FALSE)
    		{
    			frame[currentPosition] = referenceString[i] - '0';
    			isAvailable[frame[currentPosition]] = TRUE;
    			++currentPosition;
    			++missCount;
    		}
    		else
    		{
    			++hitCount;
    		}
    	}

    	else
    	{
    		if(isAvailable[referenceString[i] - '0'] == FALSE)
    		{
    			isAvailable[frame[currentPosition]] = FALSE;
    			frame[currentPosition] = referenceString[i] - '0';
    			isAvailable[frame[currentPosition]] = TRUE;
    			++currentPosition;
    			++missCount;
    		}
    		else
    		{
    			++hitCount;
    		}
    	}

    }

    /*-------------------------------------------------------------------------------------*/
    //output section

    printf("\n\n\t Number of Page Faults : %d.", missCount);
    printf("\n\n\t Number of Page Hit : %d.", hitCount);


}
