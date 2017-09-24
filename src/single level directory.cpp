#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*----------------------------------------------------------------------------------------- */
    // initializations
	int numberOfFiles;
    string fileName;
    string root;
    int i, j; //loopvar
    list<string>::iterator it;

    /*----------------------------------------------------------------------------------------- */
    //input

    cout<<"\n\n\t\t Single Level Directory \n\t\t ------ ----- ---------";
    cout<<"\n\n\t Enter the name of Main Directory : ";
    cin>>root;

    cout<<"\n\n\t Enter the number of files : ";
    cin>>numberOfFiles;
    cout<<"\n\n\t Enter the files' name : \n";
    list<string> files;

    /*----------------------------------------------------------------------------------------- */
    //single level

    for(i=0; i<numberOfFiles; i++)
    {
    	cin>>fileName;
    	files.push_back(fileName);
    }

    /*----------------------------------------------------------------------------------------- */
    //output

    cout<<"\n\n\t Representation of Files in the system : ";

    for(it = files.begin(); it != files.end(); it++)
    {
    	cout<<"\n\n\t\t"<<root<<" ---> "<<*it;
    }


}
