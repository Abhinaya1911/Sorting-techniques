#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;

int Partition(int *a,int p,int r)
{
	int x=a[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			int temp;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int swap;
	swap=a[i+1];
	a[i+1]=a[r];
	a[r]=swap;
	count++;
	return i+1;
}
void Quick_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=Partition(a,p,r);
		Quick_sort(a,p,q-1);
		Quick_sort(a,q+1,r);
	}
}
int main()
{
	ofstream outf;
	ifstream inf;
	clock_t st,end;
	double etime;
	int *a;
	int n;
	cout<<"Enter n:";
	cin>>n;
	a=new int[n];
	srand((long int)clock());
	st=clock();
	outf.open("Quicksort_in.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<rand()%50<<"\t";
	}
	outf.close();
	inf.open("Quicksort_in.txt");
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
	Quick_sort(a,1,n);
	cout<<"\nAfter sorting:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	outf.open("Quicksort_out.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<a[i]<<"\t";
	}
	outf.close();
	end=clock();
	etime=((double)(end-st))/CLOCKS_PER_SEC;
	cout<<"\n\nQuick sort:"<<endl;
	cout<<"Active operation:"<<count<<endl;
	cout<<"Execution time:"<<etime<<endl;
	delete(a);
	return 0;
}
