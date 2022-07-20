#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int c=0;

void Insertion_sort(int *a, int n)
{
	int i,j,key;
	for(j=2;j<=n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>0 && a[i]>key)
		{
			a[i+1]=a[i];
			i=i-1;
			c++;
		}
		c++;
		a[i+1]=key;
	}
}
int main()
{
	ofstream outf;
	ifstream inf;
	clock_t st,end;
	double etime;
	int n;
	int *a;
	st=clock();
	cout<<"Enter n :";
	cin>>n;
	a=new int[n];
	srand((long int)clock());
	outf.open("Insertion_In.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<rand()%50<<"\t";
	}
	outf.close();
	inf.open("Insertion_In.txt");
	for(int i=1;i<=n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	cout<<"\n Before sorting:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	c=0;
	Insertion_sort(a,n);
	cout<<"\n\n After sorting: \n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	outf.open("Insertion_Out.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<a[i]<<"\t";
	}
	outf.close();
	end=clock();
	etime=(double)(end-st)/CLOCKS_PER_SEC;
	cout<<"\nInsertion sorting:";
	cout<<"\nTotal active operation:"<<c;
	cout<<"\nExecution time:"<<etime<<"seconds\n";
	delete(a);
}

