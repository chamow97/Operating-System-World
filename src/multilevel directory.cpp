#include<bits/stdc++.h>
using namespace std;

bool search(pair<string, string> files[], int counter, string toSearch, string root)
{
    int i;

    for(i=0; i<counter; i++)
    {
        if(files[i].second == toSearch)
        {
            cout<<"\n\n\t File found path : ";
            cout<<root<<" --> "<<files[i].first<<" --> "<<files[i].second<<" .";
            return true;
        }
    }
    return false;
}

int main()
{
	/*----------------------------------------------------------------------------------------- */
    // initializations

    int i, j;//loop var
    int numberOfDirectories;
    int numberOfFiles;
    int counter = 0;
    string directoryName;
    string fileName;
    string root;

    /*----------------------------------------------------------------------------------------- */
    // input

    cout<<"\n\n\t\t Multilevel Directory Implementation \n\t\t ---------- --------- ---------------";
    cout<<"\n\n\t Enter the name of Root : ";
    cin>>root;
    cout<<"\n\n\t Enter number of Directories : ";
    cin>>numberOfDirectories;
    pair<string, string > files[1000];
    for(i=0; i<numberOfDirectories; i++)
    {
    	cout<<"\n\t Enter name of this directory : ";
    	cin>>directoryName;

    	cout<<"\n\n\t Enter number of files in this directory : ";
    	cin>>numberOfFiles;

    	for(j=0; j<numberOfFiles; j++)
    	{
    		cout<<"\n\n\t Enter the name of this file : ";
    		cin>>fileName;
    		files[counter].first = directoryName;
    		files[counter].second = fileName;
            ++counter;
    	}
    }

    /*----------------------------------------------------------------------------------------- */
    // searching

    for(;;)
    {
    	int choice;
    	cout<<"\n\n\t\t MENU\n\n\t 1. Search for a file \n\n\t 2. Exit\n\n\t Your Choice : ";
    	cin>>choice;

    	switch(choice)
    	{
    		case 1:
                {
                    string toSearch;
                    cout<<"\n\n\t Enter the name of the file to search (case sensitive) : ";
                    cin>>toSearch;
                    if(search(files, counter, toSearch, root) == false)
                    {
                        cout<<"\n\n\t File not found!!";
                    }
                    break;
                }
    		case 2:
    		return 0;
    		break;

    		default:
    		cout<<"\n\n\t Invalid Input !!";

    	}
    }


}
