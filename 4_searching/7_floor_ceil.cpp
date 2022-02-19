// Given a sorted array and a value x, the ceiling of x is the smallest element in array
// greater than or equal to x, and the floor is the greatest element smaller than or equal to x.

#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int start, int end, int x)
{
    if (start > end)
        return -1;
    if (arr[start] >= x)
    {
        return start;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] < x)
    {
        return ceilSearch(arr, mid + 1, end, x);
    }
    else if (arr[mid] > x)
    {
        return ceilSearch(arr, start, mid - 1, x);
    }
}

int floorSearch(int arr[], int start, int end, int x)
{
    if (start > end)
        return -1;
    if (arr[end] <= x)
        return arr[end];
    int mid = (start + end) / 2;
    if (arr[mid] == x)
        return arr[mid];
    if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
        return mid - 1;
    else if (arr[mid] < x)
    {
        return floorSearch(arr, mid + 1, end, x);
    }
    return floorSearch(arr, start, mid - 1, x);
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Ceiling of " << x << " doesn't exist in array ";
    else
        cout << "Ceiling of " << x << " is " << arr[index];

    index = floorSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Floor of " << x << " doesn't exist in array ";
    else
        cout << "Floor of " << x << " is " << arr[index];
    return 0;
}