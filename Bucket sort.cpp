#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
using namespace std;
long int count=0;

template<typename T>
struct Node
{
	T data;
	Node *next;	
};

template<typename T>
class SList
{
	private:
		Node<T> *a;
		int size;
	
	public:
		SList();
		bool insertFront(T);
		bool ElementAt(int,T&);
		int GetSize()	{	return size;		} 
		void Sort();
};
template<typename T>
SList<T>::SList()
{
	a = NULL;
	size = 0;
} 

template<typename T>
bool SList<T>::insertFront(T x)
{
	//New Node Creation
	Node<T> *n;
 	n = new Node<T>;
	
	if(n==NULL)
	{
		return false;
	}
	
	//Initialization
	n->data = x;
	n->next = NULL;
		
	//Link the New Node in the proper position	
	n->next = a;
	a = n;
	
	//Increase the size of the list
	size++;
	
	return true;
}

template<typename T>
bool SList<T>::ElementAt(int p, T &x)
{
	Node<T> *t = a;
	int c=1;
	while(t!=NULL)
	{
		if(c==p)
		{
			x = t->data;
			return true;
		}
		
		t = t->next;
		c++;
	}
	return false;
}

template<typename T>
void SList<T>::Sort()
{
	Node<T> *i,*j;
	double t;
	
	i = a;
	for(i=a;i!=NULL;i=i->next)
	{
		for(j = i->next;j!=NULL;j=j->next)
		{
			if(j->data<i->data)
			{
				t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
	
}
void BucketSort(double a[],int n)
{
	SList<double> *Buckets;
	Buckets = new SList<double>[n];
	
	int bNo;
	for(int i=0;i<n;i++)
	{
		bNo = a[i]*n;
		Buckets[bNo].insertFront(a[i]);
		count++;
	}
	
	for(int i=0;i<n;i++)
	{
		count++;
		Buckets[i].Sort();
	}
	
	//Concatenating buckets
	double t;
	for(int i=0,j=0;i<n;i++)
	{
		for(int p=1;p<=Buckets[i].GetSize();p++)
		{
			count++;
			if(Buckets[i].ElementAt(p,t))
			{
				a[j++] = t;
			}
		}

	}
}

int main()
{
	
	ofstream outf;
	ifstream inf;
	clock_t st,end;
	double etime;
	int n;
	double *a;
	st=clock();
	cout<<"\nEnter n:";
	cin>>n;
	a = new double [n];
	//Counting the maximum number of digits. Max value is n-1
	int tmp=n-1,d=0;
	while(tmp!=0)
	{
		d++;
		tmp/=10;
	}
	srand((long int)clock());
	//Loading numbers to input file
	outf.open("Bucket_in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<(double)((rand()%n)/pow(10,d))<<"\t";
	}
	outf.close();
	inf.open("Bucket_in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
		cout<<a[i]<<"\t";
	}
	inf.close();
	count = 0;
	BucketSort(a,n);
	//Writing sorted numbers to output file
	cout<<"\nBucket sort - Output\n";
	outf.open("BucketOut.txt");
	for(int i=0;i<n;i++)
	{
		outf<<a[i]<<"\t";
		cout<<a[i]<<"\t";
	}
	end = clock();
	etime = (double)(end-st)/CLOCKS_PER_SEC;
	outf.close();
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<etime<<" Seconds\n";
	delete(a);
	
}


