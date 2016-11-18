//Bubble sort using recursion.....
//edited by Suprotik Dey..
#include <stdio.h>
#define MAX 100


/*
A short note about bubble sorting....
Taken from wikipedia.org

Bubble sort, sometimes referred to as sinking sort, 
is a simple sorting algorithm that repeatedly steps through the list to be sorted, 
compares each pair of adjacent items and swaps them if they are in the wrong order. 
The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted. 
The algorithm, which is a comparison sort, 
is named for the way smaller or larger elements "bubble" to the top of the list.
Although the algorithm is simple, 
it is too slow and impractical for most problems even when compared to insertion sort.
It can be practical if the input is usually in sorted order 
but may occasionally have some out-of-order elements nearly in position.
--------------------------------------------------------------------------------------------

Bubble sort has worst-case and average complexity both O(n^2),
where n is the number of items being sorted. 

------------------------------------------------------------------------------------------------

Working of recursive functions...

When a function calls itself from within itself,it is known as recursive function..
Understand particularly that recursive functions are NOT EASY FOR THE COMPUTER TO COMPUTE.
IT TAKES MORE MEMORY!!
-----------------------------------------------------------------------------------------------

Why recursion???

Because its easy to implement.

*/



//actual function..
void BubbleSort (int *arr, int s) //arr is the array, s is the real size of array.
{
	if( s == 1)  //end condition for recursion..Return if length of array is 1
		return;
		
	int j, temp; //j is the counter

	for(j = 0; j < s-1; j++ ) //loop starts from 0 upto the second last element since it compares with the next element
	{
		if( arr[j] > arr[j+1] ) //if next one is greater than previous one.
		{
			temp = arr[j];  //swapping...
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
	BubbleSort(arr, s-1); //recursive calling with sizew decreased by 1.
	return;
}

/*
Actual working of the above function...

So lets take an example:

5, 1, 4, 2, 8
array size = 5

it is not sorted..
So we send the array pointer and its size from the calling function

so firstly it checks for if size==1
NO then continue...

( 5 1 4 2 8 ) to  ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
  ^ ^
( 1 5 4 2 8 ) to  ( 1 4 5 2 8 ), Swap since 5 > 4
    ^ ^
( 1 4 5 2 8 ) to ( 1 4 2 5 8 ), Swap since 5 > 2
      ^ ^
( 1 4 2 5 8 ) Now, since these elements are already in order (8 > 5), algorithm does not swap them.
        ^ ^
SEE carefully that the greatest element has been shifted to the last position becoming the sorted part..
then it sends the array with size 4
 
1, 4, 2, 5
 
( 1 4 2 5 ) no change
  ^ ^
( 1 4 2 5 ) to  ( 1 2 4 5 8 ), Swap since 4 > 2
    ^ ^
( 1 2 4 5 ) no change
      ^ ^
-------------------------------------------------------------------------------------
it will again change the array to another recursion of the function with size-1 as new size....
And will continue sending until the size is decreased to 1

1 2 4

1 2

1   ->The array has size 1 so the function will return to the calling function....

then you will see the final array to be 1 2 4 5 8
*/

//driver program....
int main()
{
	int inputB[MAX], size, i, val;
	
	printf("\nEnter size of array:");//size input
	scanf("%d", &size);
	
	printf("\nEnter an array:\n");
	for ( i = 0; i<size; i++ )   //array input
	{
		scanf("%d",&inputB[i]);
	}
	
	printf("\nYour entered array:\n");
	for( i = 0; i < size; i++ )   //original array print
    {
        printf("%d ",inputB[i]);
    }

    BubbleSort(inputB, size);

	printf("\nThe bubble sorted array:\n");
	for( i = 0; i < size; i++ )  //sorted array print
    {
        printf("%d ",inputB[i]);
    }

	return 0;
}
