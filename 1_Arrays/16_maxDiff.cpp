#include<bits/stdc++.h>
using namespace std;

int maxDiff(int arr[],int n)
{
    int minEle = arr[0],maxDiff = INT_MIN,i;

    for(i=1;i<n;i++)
    {
        if(arr[i]<minEle)
            minEle = arr[i];
        else
        {
            int diff = arr[i]-minEle;

            if(diff>maxDiff)
            {
                maxDiff = diff;
            }
        }

    }

    return maxDiff;


}

int main()
{
  int arr[] = {1, 2, 90, 10, 110};
  int n = sizeof(arr) / sizeof(arr[0]);
   
  cout << "Maximum difference is " << maxDiff(arr, n);
 
  return 0;    
}