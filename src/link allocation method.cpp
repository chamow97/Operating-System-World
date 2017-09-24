#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node()
	{
		data = 0;
		next = nullptr;
	}
};

int main()
{
	/*----------------------------------------------------------------------------------------- */
    // initializations

    int startingPosition = 0, blockSize;
    string fileName;
    int i, j; //loopvar

    /*----------------------------------------------------------------------------------------- */
    //input

    cout<<"\n\n\t Linked File Allocation\n\t ------ ---- ----------";
    cout<<"\n\n\t Enter the name of file : ";
    cin>>fileName;
    cout<<"\n\n\t Enter the starting position : ";
    cin>>startingPosition;
    cout<<"\n\n\t Enter the block size : ";
    cin>>blockSize;

    /*----------------------------------------------------------------------------------------- */
    //again initializations

    node *head = new node();
    node *top = new node();
    cout<<"\n\n\t Enter the block number(s) : ";
    
    /*----------------------------------------------------------------------------------------- */
    //input and linked list implementation

    for(i=0; i<blockSize; i++)
    {
        node *temp = new node();
        cin>>temp->data;
        temp->next = nullptr;
        if(i == 0)
        {
            top = temp;
            head = temp;
        }
        else
        {
            head->next = temp;
            head = temp;
        }
    }

    /*----------------------------------------------------------------------------------------- */
    //output
    
    cout<<"\n\n\t The file allocation style is as follows : ";
    cout<<startingPosition<<" -> ";
    while(top != nullptr)
    {
        if( top->next == nullptr )
        {
            cout<<top->data<<".";
        }
        else
        {
            cout<<top->data<<" -> ";
        }

        top = top->next;
    }

}
