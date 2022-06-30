#include <bits/stdc++.h>
using namespace std;

int partion(vector<int> &arr, int lb, int ub){
    int pivot=arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}

int quickSelect(vector<int> &arr, int left, int right, int k)
{
    int j = partion(arr, left, right);
    if (j == k)
        return arr[j];
    else if (j > k)
        return quickSelect(arr, left, j - 1, k);
    else
        return quickSelect(arr, j + 1, right, k);
}

int main()
{
    vector<int> arr = {3, 6, 1, 10, 2, 12};
    cout<<quickSelect(arr, 0, arr.size() - 1, 2)<<endl;
}