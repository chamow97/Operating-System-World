#include<stdio.h>

#define TRUE 1
#define FALSE 0

struct PageTable {
	int frameNumber;
	int isPresent;
};

struct FrameTable {
	int pageNumber;
};

int main()
{
	/*-------------------------------------------------------------------------------------*/
    //initialisation section
	int baseAddress, logicalAddress, offsetValue, physicalAddress;
    int physicalSize, logicalSize, partitionSize, numberOfFrames, numberOfPages;
    int temp;
    int i; //loopvar
    struct PageTable Page[1000];
    struct FrameTable Frame[1000];

	/*-------------------------------------------------------------------------------------*/
    //input

    printf("\n\n\t\t PAGING HARDWARE\n\t\t ------ --------");
	printf("\n\n\t Enter the size of physical memory : ");
	scanf("%d", &physicalSize);
	printf("\n\n\t Enter the size of logical memory : ");
	scanf("%d", &logicalSize);
	printf("\n\n\t Enter the partition size : ");
	scanf("%d", &partitionSize);

	//computing the number of frames and pages
	numberOfFrames = (physicalSize/partitionSize);
	numberOfPages = (logicalSize/partitionSize);

	/*-------------------------------------------------------------------------------------*/
	//some initialisations

	for(i=0; i<numberOfPages; i++)
	{
		Page[i].frameNumber = -1;
		Page[i].isPresent = FALSE;
	}

	for(i=0; i<numberOfFrames; i++)
	{
		Frame[i].pageNumber = -2;
	}

	/*-------------------------------------------------------------------------------------*/
	//placing of pages

	for(i=0; i<numberOfPages; i++)
	{
		printf("\n\n\t Enter the frame where page %d should be placed : ", i);
		scanf("%d", &temp);
		Frame[i].pageNumber = i;

		if(Page[i].isPresent == FALSE)
		{
			Page[i].frameNumber = temp;
			Page[i].isPresent = TRUE;
		}
	}

	/*-------------------------------------------------------------------------------------*/
	//displaying page table

	printf("\n\n\t\t PAGE TABLE \n\t\t ---- -----");
	printf("\n\n\t\t Page Address \t    Frame Number \t Presence");

	for(i=0; i<numberOfPages; i++)
	{
		if(Page[i].isPresent == TRUE)
		{
			printf("\n\n\t\t     %d  \t          %d   \t\t   TRUE", i, Page[i].frameNumber);
		}
		else
		{
			printf("\n\n\t\t     %d  \t          %d   \t\t   FALSE", i, Page[i].frameNumber);
		}
	}

	/*-------------------------------------------------------------------------------------*/
	//displaying physical address

	printf("\n\n\t\t PHYSICAL ADDRESS \n\t\t -------- -------");
	printf("\n\n\t\t Frame Address \t\t        Page Number");

	for(i=0; i<numberOfFrames; i++)
	{
		printf("\n\n\t\t%d \t\t\t\t   %d", i, Frame[i].pageNumber);
	}

	/*-------------------------------------------------------------------------------------*/
	//to find frame number of a given page

	printf("\n\n\t Enter the base address : ");
	scanf("%d", &baseAddress);

	printf("\n\n\t Enter the logical address : ");
	scanf("%d", &logicalAddress);

	printf("\n\n\t Enter the offset address : ");
	scanf("%d", &offsetValue);

	//calculation of physical address

	physicalAddress = (baseAddress) + (Page[logicalAddress / partitionSize].frameNumber * partitionSize) + offsetValue;

	printf("\n\n\t\t The Physical Address is : %d .", physicalAddress);

}
