#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count = 0;

int LEFT(int i)
{
	return 2*i;
}
int RIGHT(int i)
{
	return (2*i)+1;
}
void Max_Heapify(int *a,int i,int n)
{
	int l,r,largest;
	l=LEFT(i);
	r=RIGHT(i);
	if(l<=n && a[l]>a[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<=n && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		int temp;
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		Max_Heapify(a,largest,n);
	}
}
void Build_Max_Heap(int *a,int n)
{
	for(int i=n/2;i>=1;i--)
	{
		Max_Heapify(a,i,n);
	}
}
Heap_sort(int *a,int n)
{
	Build_Max_Heap(a,n);
	for(int i=n;i>=2;i--)
	{
		int temp;
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		n=n-1;
		Max_Heapify(a,1,n);
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
    cout<<"Enter n:";
    cin>>n;
    st=clock();
    a=new int[n];
    srand((long int)clock());
    outf.open("HeapSort_IN.txt");
    for(int i=1;i<=n;i++)
	{
        outf<<rand()%50<<"\t";
    }
    outf.close();
    inf.open("HeapSort_IN.txt");
    for(int i=1;i<=n;i++)
	{
        inf>>a[i];
    }
    inf.close();
    cout<<endl;
    cout<<"Before Sorting"<<endl;
    for(int i=1;i<=n;i++)
	{
        cout<<a[i]<<"\t";
    }
    count =0;
    Heap_sort(a,n);
    cout<<"\nAfter Sorting"<<endl;
    for(int i=1;i<=n;i++)
	{
        cout<<a[i]<<"\t";
    }
    outf.open("HeapSort_OUT.txt");
    for(int i=1;i<=n;i++){
        outf<<a[i]<<"\t";
    }
    outf.close();
    end=clock();
    
    etime = ((double)(end-st))/CLOCKS_PER_SEC;
    cout<<"\n\nHEAP SORT:"<<endl;
    cout<<"Total Active Operations:"<<count<<endl;
    cout<<"Execution time:"<<etime<<endl;
    delete(a);
    return 0;
}

