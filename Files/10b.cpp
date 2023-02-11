#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

class telephone
{
	public:
		long long number;
		string name;
		void getdata()
		{
			cout<<"Enter name: ";
			getline(cin,name);
			cout<<"Enter number: ";
			cin>>number;
		}
		void display()
		{
			cout<<"Name : "<<name<<"Number : "<<number<<endl;
		}
		
};

void search(int n, telephone t[])
{
	string s;
	cin.ignore();
	cout<<"Enter name to Search: ";
	getline(cin,s);
	
	ifstream fin;
	fin.open("Telephone Directory.txt");
	int i;
	for(i=0;i<n;i++)
	{
		fin>>t[i].name>>t[i].number;
		if(t[i].name==s)
		{
			cout<<"Name : "<<t[i].name<<"\t Number: "<<t[i].number<<endl;
			break;	
		}
	}
	if(i==n)
		cout<<"Not present\n";
}

void update(int n,telephone t[])
{
	string s;
	cin.ignore();
	cout<<"Enter name to Update Details: ";
	getline(cin,s);
	
	ifstream fin;
	fin.open("Telephone Directory.txt");
	int i;
	for(i=0;i<n;i++)
	{
		fin>>t[i].name>>t[i].number;
		if(t[i].name==s)
		{
			cout<<"Enter new number to update: ";
			cin>>t[i].number;
			break;
		}
	}
	if(i==n)
		cout<<"Not present\n";
	fin.close();
	
	ofstream fout;
	fout.open("Telephone Directory.txt");
	for(i=0;i<n;i++)
		fout<<setw(15)<<t[i].name<<setw(10)<<t[i].number<<endl;
	
	fout.close();
}

int main()
{
	int n;
	cout<<"Enter number of contacts in the Telephone Directory: ";
	cin>>n;
	
	telephone t[n];
	
	ofstream fout;
	fout.open("Telephone Directory.txt");	
	for(int i=0;i<n;i++)
	{
		cin.ignore();
		t[i].getdata();
		fout<<setw(15)<<t[i].name<<setw(10)<<t[i].number<<endl;
	}
	fout.close();
	
	int ch;
	do
	{
		cout<<"\n1.Search\n2.Update number\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:search(n,t);break;
			case 2:update(n,t);break;
			case 3:break;
			default:cout<<"Invalid input.\n";
		}	
	}while(ch!=3);
	return 0;
}

