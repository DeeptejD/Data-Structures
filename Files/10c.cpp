#include<iostream>
#include<fstream>
using namespace std;
class student
{
	char name[50];
	char address[50];
	char branch[50];
	int rollno;
	public:
		int getrollno()
		{   
			return rollno;
		}
	    char * getname()
		{
			return name;
		}
		void getdata(void);
		void putdata(void);
};
void student::getdata(void)
{
	fflush(stdin);
	cout<<"\nEnter name : ";fgets(name,50,stdin);
	fflush(stdin);
	cout<<"Enter roll no : ";cin>>rollno;
	fflush(stdin);
	cout<<"Enter Address : ";fgets(address,50,stdin);
	fflush(stdin);
	cout<<"Enter branch : ";fgets(branch,50,stdin);
}
void student::putdata(void)
{
	cout<<"NAME : "<<name<<" ";
	cout<<"ROLLNO : "<<rollno<<" ";
	cout<<"ADDRESS : "<<address<<" ";
	cout<<"BRANCH : "<<branch<<endl;
}
int main()
{
	int choice;
	student stud;
	while(1)
	{
		cout<<"\n";
		cout.fill('-');
		cout.width(35);cout<<"Menu";cout.width(30);cout<<"-";
		cout<<"\n1.Add the entry ";
		cout<<"\n2.Search ";
		cout<<"\n3.update the entry";
		cout<<"\n4.Quit";
		fflush(stdin);
		cout<<"\nchoose from menu : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"\n";cout.width(35);cout<<"ADD THE ENTRY";cout.width(30);cout<<"-";
				stud.getdata();
				string s;
				int n=stud.getrollno();
				while(n)
				{
					int k=n%10;
					n=n/10;
					char c=k+'0';
					s=c+s;
				}
				ofstream file(s);
				file.write((char *)&stud, sizeof(stud));
				break;
			}
			case 2:
			{
				cout<<"\n";cout.width(35);cout<<"SEARCH";cout.width(30);cout<<"-";
				int n;
				cout<<"\nEnter Roll Number to search : ";
				fflush(stdin);
				cin>>n;
				string s;
				while(n)
				{
					int k=n%10;
					n=n/10;
					char c=k+'0';
					s=c+s;
				}
				ifstream file(s);
				if(file.good())
				{
					file.read((char *)&stud,sizeof(stud));
					stud.putdata();
				}
				else
					cout<<"\n"<<n<<" student is not there in record";
					break;
			}
			case 3:
			{
				fflush(stdin);
				cout<<"\n";cout.width(35);cout<<"UPDATE";cout.width(30);cout<<"-";
 				cout<<"\nEnter roll no of student to be updated : ";
 				int n;
				string s;
				cin>>n;
				while(n)
				{
					int k=n%10;
					n=n/10;
					char c=k+'0';
					s=c+s;
				}
				char k[100];
				int l=s.size();
				for(int i=0;i<l;i++)
				k[i]=s[i];
				ofstream file(s,ios::trunc);
 				if(file.good())
 				{
 					cout<<"Enter new data";
 					stud.getdata();
 					file.write((char *)&stud,sizeof(stud))<<flush;
 					rename(k,stud.getname());
				}
				else
 					cout<<"\n"<<n<<" student is not there in record";
					break;
			}
		case 4:
		{
			exit(1);
		}
		default:
		{
			cout<<"\ninvalid choice ";
			break;
		}
 	}
}
return 0;
}

