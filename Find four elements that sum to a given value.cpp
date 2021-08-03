/*
Niave approach is to generate quadruples one by one using 4 loops TC = O(N^4)

ROUGH

{10,20,30,40,1,2}

//sort

{1,2,10,20,30,40}

2 loop as it is rehenge just 3rd and 4th loop ki jagah 2 pointer approach use karo

current sum = a[i]+a[j]+a[left]+a[right]

agar current sum <X
right--
agar current sum >X
left++

aisa tab tak karo while(l<r)

TC = O(n^3)

*/


#include<iostream>
#include<algorithm>  //to use sort()
   
using namespace std;

void findFourElements(int a[],int n,int  X)
{
	//sort the array first
	sort(a,a+n);
	
	//2 pointers in thirs loop
	int l;
	int r=n-1;  //ye last hi hoga
	
	for(int i=0;i<n-3;i++)  //teen elements fix karre isiliye n-3, i agar < n hua to j=i+1 = limit ke bahar chala jaayga
	{
		for(int j=i+1;j<n-2;j++)//ek element fix hai already, j agar < n hua to k=j+1 = limit ke bahar chala jaayga
		{
			l=j+1; //first 2 to fix hai
			while(l<r)
			{
				if(a[i]+a[j]+a[l]+a[r]==X)
				{
					cout<<"\n { "<<a[i]<<","<<a[j]<<","<<a[l]<<","<<a[r]<<" } ";
					l++;
					r--;
				}
				else if(a[i]+a[j]+a[l]+a[r]<X) 
				{
					l++;
				}
				else if(a[i]+a[j]+a[l]+a[r]>X) 
				{
					r--;
				}
			}
		}
	}
}

int main()
{
	int A[] = {10, 2, 3, 4, 5, 9, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int X = 23;
    findFourElements (A, n, X);	
	
	
return 0;
}
