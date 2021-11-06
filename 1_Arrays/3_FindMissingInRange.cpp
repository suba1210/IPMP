/*
Approach 1: The length of the array is n-1. So the sum of all n elements, i.e sum of numbers from 1 to n 
can be calculated using the formula n*(n+1)/2. Now find the sum of all the elements in the array 
and subtract it from the sum of first n natural numbers, it will be the value of the missing element.

Approach 2 : The approach remains the same but there can be overflow if n is large. In order to avoid 
integer overflow, pick one number from known numbers and subtract one number from given numbers. 
This way there won’t have Integer Overflow ever. That means subtracting each step by step.

Approach 3 : using bitwise xor
XOR has certain properties 
Assume a1 ^ a2 ^ a3 ^ …^ an = a and a1 ^ a2 ^ a3 ^ …^ an-1 = b
Then a ^ b = an

*/

#include <bits/stdc++.h>
using namespace std;

// approach 1 is easy, just find sum using the formula and add sum , then subtract both of them

int getMissingNo3(int a[], int n)
{

	int x1 = a[0];
	int x2 = 1;
	for (int i = 1; i < n; i++)
		x1 = x1 ^ a[i];

	for (int i = 2; i <= n + 1; i++)
		x2 = x2 ^ i;

	return (x1 ^ x2);
}

int getMissingNo2(int arr[], int n)
{
    int i, total=1;
     
    for ( i = 2; i<= (n+1); i++)
    {
        total+=i;
        total -= arr[i-2]; // here basically, we are subtracting step by step
    }
    return total;

}

int main()
{
	int arr[] = { 1, 2, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int miss2 = getMissingNo2(arr, n);
	int miss3 = getMissingNo3(arr, n);
	cout << miss3;
}

