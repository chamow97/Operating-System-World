#include<stdio.h>

int wait(int s)
{
    while(s <= 0);
    s--;
    return s;
}
int signal(int s)
{
    s++;
    return s;
}
int minimum(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
int main()
{
	/*-------------------------------------------------------------------------------------*/
    //declaration section
	int numberOfPhilisophers;
	int p1, p2;
	int chopsticks[100];
	int eat[100];
	int first;
	int i, k=0; //loop var
	int flag[] ={0,0};

	/*-------------------------------------------------------------------------------------*/
    //input section

    printf("\n\n\t\t DINING PHILOSOPHER PROBLEM\n\t ------ ----------- -------");
    printf("\n\n\t Enter the number of philosophers : ");
    scanf("%d", &numberOfPhilisophers);

    printf("\n\n\t Enter the ID of 2 Philosophers : ");
    scanf("%d %d", &p1, &p2);

    /*-------------------------------------------------------------------------------------*/
    //initialisation

    for(i=0; i<numberOfPhilisophers; i++)
    {
    	chopsticks[i] = 1;
    }
    first = minimum(p1, p2);

    /*-------------------------------------------------------------------------------------*/
    //dining time!!

    while(first < numberOfPhilisophers)
    {
    	if(chopsticks[first] == 1 && chopsticks[(first+1) % numberOfPhilisophers] == 1)//its a round table
    	{
    		chopsticks[first] = wait(chopsticks[first]);
    		chopsticks[(first + 1) % numberOfPhilisophers] = wait(chopsticks[(first + 1) % numberOfPhilisophers]);
    		eat[k] = first;
    		++k;
    	}
    	++first;
    }
    for(i=0; i<k; i++)
    {
        if(eat[i] == p1)
        {
            flag[0] = 1;
        }
        else if(eat[i] == p2)
        {
            flag[1] = 1;
        }
    }
    if(flag[0] == 1)
    {
        printf("\n\n\tPhilosopher : %d eats.", p1);
    }
    else if(flag[0] == 0)
    {
        printf("\n\n\tPhilosopher : %d thinks.", p1);
    }
    if(flag[1] == 1)
    {
        printf("\n\n\tPhilosopher : %d eats.", p2);
    }
    else
    {
        printf("\n\n\tPhilosopher : %d thinks.", p2);
    }

    printf("\n\n\t Philosopher who can eat at same time : ");

    for(i=0; i<k; i++)
    {
        printf("%d ",eat[i]);
    }
    i = p1;
    while(i < numberOfPhilisophers)
    {
        if(chopsticks[i] == 0 && chopsticks[(i+1)%numberOfPhilisophers] == 0)
        {
            chopsticks[i] = signal(chopsticks[i]);
            chopsticks[(i+1)%numberOfPhilisophers] = signal(chopsticks[(i+1)%numberOfPhilisophers]);

        }
        i++;
    }

    return 0;
}
