// #include<bits/stdc++.h>
// using namespace std;

//     int firstMissingPos(int arr[], int n) 
//     { 
//         int i;

//         if(n==0)
//             return 0;
        
//         for(i=0;i<n;i++)
//         {
//             while(arr[i]>0 && arr[i]<n && arr[i]!=arr[arr[i]-1])
//             {
//                 swap(arr[i],arr[arr[i]-1]);
//             }
//         }
        
//         for(i=0;i<n;i++)
//         {
//             if(arr[i]!=i+1)
//             {
//                 return i+1;
//             }
//         }
        
//         return n+1;
//     }

// int main()
// {
//     int A[] = {1,2,3,4,5};
//     int size = sizeof(A) / sizeof(A[0]);
//     cout << firstMissingPos(A, size);    
// }

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
    int k = n;
    if (n==0)
    {
        return 0;
    }
    for(int i = 0; i<k; i++)
    {
        while(arr[i] > 0 && arr[i] < k && arr[arr[i] - 1] != arr[i])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    for(int i = 0; i < k; i++)
    {
        if(arr[i] != i + 1)
        {
            return i + 1;
        }}
    return k + 1;
}};

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends