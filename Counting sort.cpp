#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;

void Counting_sort(int *a,int *b,int k,int length)
{
	int *c;
	c=new int[k];
	for(int i=0;i<=k;i++)
	{
		c[i]=0;
		count++;
	}
	for(int j=1;j<=length;j++)
	{
		c[a[j]]=c[a[j]]+1;
		count++;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
		count++;
	}
	for(int j=length;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
		count++;
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
	int *b;
	st=clock();
	cout<<"Enter n :";
	cin>>n;
	a=new int[n];
	b=new int[n];
	srand((long int)clock());
	outf.open("Counting_In.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<rand()%50<<"\t";
	}
	outf.close();
	inf.open("Counting_In.txt");
	for(int i=1;i<=n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	cout<<"\nBefore sorting:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	count=0;
	int k=50;
	Counting_sort(a,b,k,n);
	cout<<"\nAfter sorting: \n";
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<"\t";
	}
	outf.open("Counting_Out.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<b[i]<<"\t";
	}
	outf.close();
	end=clock();
	etime=(double)(end-st)/CLOCKS_PER_SEC;
	cout<<"\nCounting sorting:";
	cout<<"\nTotal active operation:"<<count;
	cout<<"\nExecution time:"<<etime<<"seconds\n";
	delete(a);
	delete(b);
	return 0;
}

