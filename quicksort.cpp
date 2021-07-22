#include<iostream>
using namespace std;
int A[100];
int n;
void display()
{
	int i;
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<"\t";
	}
	
	
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int l,int h)
{
	int pivot=A[l];
	int i=l,j=h;
	while(i<j){
		do{
			i++;
		}while(A[i]<=pivot);
		do{
			j--;
		}while(A[j]>pivot);
		if(i<j)
		swap(&A[i],&A[j]);
		display();
		cout<<"\t"<<"pivot:"<<pivot;
	}
	swap(A[l],A[j]);
	return j;
}
void quicksort(int l,int h)
{
	if(l<h)
	{
		int j=partition(l,h);
		quicksort(l,j);
		quicksort(j+1,h);
	}
}
int main()
{
int i;
cout<<"Enter Size of Array:";
cin>>n;
cout<<"Enter "<<n<<" elements:";
for(i=0;i<n;i++){
	cin>>A[i];
}
cout<<"Array before sorting:"<<endl;
display();
quicksort(0,n);
cout<<"\nArray after sorting:"<<endl;
display();	
}
