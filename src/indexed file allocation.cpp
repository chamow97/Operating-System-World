#include<bits/stdc++.h>
using namespace std;


int main()
{
	/*----------------------------------------------------------------------------------------- */
    // initializations

    int startingPosition = 0, blockSize;
    string fileName;
    int i, j; //loopvar

    /*----------------------------------------------------------------------------------------- */
    //input

    cout<<"\n\n\t Indexed File Allocation\n\t ------ ---- ----------";
    cout<<"\n\n\t Enter the name of file : ";
    cin>>fileName;
    cout<<"\n\n\t Enter the starting position : ";
    cin>>startingPosition;
    cout<<"\n\n\t Enter the block size : ";
    cin>>blockSize;

    /*----------------------------------------------------------------------------------------- */
    //again initializations

    list<int> *index = new list<int>[blockSize];
    cout<<"\n\n\t Enter the block number(s) : ";

    /*----------------------------------------------------------------------------------------- */
    //input and linked list implementation using a array of linked list(a single block to store the path)

    for(i=0; i<blockSize; i++)
    {
        int temp;
        cin>>temp;
        index[i].push_back(temp);
    }

    /*----------------------------------------------------------------------------------------- */
    //output

    cout<<"\n\n\t The file allocation style is as follows : ";
    cout<<startingPosition<<" -> ";
    for(i=0; i<blockSize; i++)
    {
        list<int>::iterator it;
        if( i == blockSize - 1)
        {
            for(it = index[i].begin(); it != index[i].end(); it++)
            {
                cout<<*it<<".";
            }
        }
        else
        {
            for(it = index[i].begin(); it != index[i].end(); it++)
            {
                cout<<*it<<" -> ";
            }
        }

    }

}
