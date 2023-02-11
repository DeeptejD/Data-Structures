/*Write a C++ program to insert 5 elements in first file and 3 elements in second file. Merge
the contents of both files into third file into ascending order.*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("File_1");	//constructor to open file
    //fout.open("File_1");

    int element,i,j,temp;
    cout<<"Enter integer elements of files 1: ";
    for(i=1;i<=5;i++)
    {
        cin>>element;
        fout<<element<<" ";
    }
    fout.close();

    fout.open("File_2");		//open() to open file
    cout<<"Enter integer elements of files 2: ";
    for(i=1;i<=3;i++)
    {
        cin>>element;
        fout<<element<<" ";
    }
    fout.close();

    ifstream fin;
    fin.open("File_1");
    int arr[8];
    i=0;
    while(!fin.eof())
    {
        fin>>arr[i];
        fin.get();
        i++;
    }
    i--;
    fin.close();

    fin.open("File_2");
    while(!fin.eof())
    {
        fin>>arr[i];
        fin.get();
        i++;
    }

    for(i=0;i<8;i++)
    {
        for(j=i+1;j<8;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    fout.open("File_3");
    fout<<"Sorted Merged Data: ";
    cout<<endl<<"Contents of File 3: ";
    for(i=0;i<8;i++)
    {
    	fout<<arr[i]<<" ";
    	cout<<arr[i]<<" ";
	}
        
}
