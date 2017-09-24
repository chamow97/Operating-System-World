#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

int LRUFinder(char referenceString[], int isAvailable[], int position)
{
	/*-------------------------------------------------------------------------------------*/
    //initialisation section
    int isAvailableTemp[10];
	int i; // loop var
	--position;
	for(i=0; i<10; i++)
    {
        isAvailableTemp[i] = isAvailable[i];
    }

	/*-------------------------------------------------------------------------------------*/
    //LRU finder

	for(i=position; i>=0; i--)
	{
		if(isAvailableTemp[referenceString[i] - '0'] == TRUE)
		{
			position = referenceString[i] - '0';
			isAvailableTemp[referenceString[i] - '0'] = FALSE;
		}

	}

	//if all pages are recently used spit the minimum position

		return position;

}

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

    printf("\n\n\t\t LRU Page Replacement Algorithm!\n\t\t ----- ---- ----------- ---------");
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
    //LRU Algorithm

    currentPosition = 0;
    //initially fill the frame
    /* fill the frames if page is not available, if the page is available in frame, do not add again
    	isAvailable tells whether the ith page is present or not*/

    for(i=0; i<length; i++)
    {
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
    			int pageToReplace = LRUFinder(referenceString, isAvailable, i);
    			for(j=0; j<numberOfFrames; j++)
    			{
    				if(pageToReplace == frame[j])
    				{
    					break;
    				}
    			}
    			currentPosition = j;
    			isAvailable[frame[currentPosition]] = FALSE;
    			frame[currentPosition] = referenceString[i] - '0';
    			isAvailable[frame[currentPosition]] = TRUE;
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
