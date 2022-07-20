#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;

void Merge(int *a,int p,int q,int r)
{
	int n1,n2;
	int *L,*R;
	int i,j;
	n1=q-p+1;
	n2=r-q;
	L=new int[n1+1];
	R=new int[n2+1];
	for(int t=1;t<=n1;t++)
	{
		L[t]=a[p+t-1];
	}
	for(int t=1;t<=n2;t++)
	{
		R[t]=a[q+t];
	}
	L[n1+1]=100000;
	R[n2+1]=100000;
	i=1;j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i+=1;
			count++;
		}
		else
		{
			a[k]=R[j];
			j+=1;
			count++;
		}
	}
}
void Merge_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=((p+r)/2);
		Merge_sort(a,p,q);
		Merge_sort(a,q+1,r);
		Merge(a,p,q,r);
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
	outf.open("Merge_In.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<rand()%50<<"\t";
	}
	outf.close();
	inf.open("Merge_In.txt");
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
	count=0;
	Merge_sort(a,1,n);
	cout<<"\n\n After sorting: \n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	outf.open("Merge_Out.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<a[i]<<"\t";
	}
//	cout<<"hi";
	outf.close();
	end=clock();
	etime=(double)(end-st)/CLOCKS_PER_SEC;
	cout<<"\nMerge sorting:";
	cout<<"\nTotal active operation:"<<count;
	cout<<"\nExecution time:"<<etime<<"seconds\n";
	delete(a);
}

