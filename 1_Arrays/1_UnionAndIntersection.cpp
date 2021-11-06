#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,i,j;
    cin>>n1>>n2;
    int temp;
    set<int> arr1,arr2;

    for(i=0;i<n1;i++)
    {
        cin>>temp;
        arr1.insert(temp);
    }
    for(i=0;i<n2;i++)
    {
        cin>>temp;
        arr2.insert(temp);
    }

    set<int> union1;
    set<int> intersec;


    for(auto x : arr1)
    {
        union1.insert(x);
    }

    for(auto x : arr2)
    {
        union1.insert(x);
    }

    for(auto x: arr1)
    {
        if(arr2.find(x)!= arr2.end())
        {
            intersec.insert(x);
        }
    }

    cout<<"\nUnion : \n";

    for(auto x : union1)
    {
        cout<<x<<" ";
    }

    cout<<"\nIntersection : \n";

    for(auto x : intersec)
    {
        cout<<x<<" ";
    }
}

//Time complexity : O(logn) since insert and delete operations are O(logn) operations
//Space Complexity : O(n)

//using sorted arrays :
/*
void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            printf(" %d ", arr1[i++]);
        else if (arr2[j] < arr1[i])
            printf(" %d ", arr2[j++]);
        else {
            printf(" %d ", arr2[j++]);
            i++;
        }
    }
  
    //for printing remaining elements
    while (i < m)
        printf(" %d ", arr1[i++]);
    while (j < n)
        printf(" %d ", arr2[j++]);
}

void printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else 
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

*/