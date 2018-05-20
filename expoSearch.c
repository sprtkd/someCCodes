//exponential search

#include <stdio.h>

int binSearch(int *arr,int start, int len, int n)
{
	int mid,l,r;
	
	l= start;
	r=len;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(arr[mid-1]==n)
			return mid-1;
		else if(n>arr[mid-1])
			l=mid+1;
		else
			r=mid-1;
	}
	
	return -1;
}

int expoSearch(int *arr, int len, int n)
{
	if(arr[0]==n)
		return 0;
		
	int r=1;
	while(r<n && arr[r]<=n)
		r=r*2;
		
	if(r>n)
		r=n;
	
	return binSearch(arr,r/2,r,n);
	
	
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,38,39,40,46,47,48,49,50,52,53,54,55,5761,62,63,64,65,66,70,71,72,77,78,79,80,81,82,83,84,85,90,91,92,93,94,99,100};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	
	printf("\nFound at: %d. (0 means not present)",expoSearch(arr,arrlen,85)+1);
}
