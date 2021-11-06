// #include<bits/stdc++.h>
// using namespace std;

// class pairSum{
//     public:
//     int sum,first,second;
// };

// int compare(const void* a , const void* b)
// {
//     return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
// }

// bool checkCommon(pairSum a, pairSum b)
// {
//     if((a.first==b.first)||(a.first==b.second)||(a.second==b.first)||(a.second==b.second))
//         return false;
//     else
//         return true;
// }

// void findFourElements(int arr[],int n,int x)
// {
//     int i,j;
//     int size = (n*(n-1))/2;
//     int k=0;
//     pairSum aux[size];

//     for(i=0;i<n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             aux[k].first = i;
//             aux[k].second = j;
//             aux[k].sum = arr[i]+arr[j];
//             k++;
//         }
//     }

//     qsort(aux,size,sizeof(aux[0]),compare);

//     int l=0,r=size-1;

//     while(l<size && j>=0)
//     {
//         if((aux[l].sum+aux[r].sum==x) && checkCommon(aux[l],aux[r]))
//         {
//             cout<<arr[aux[l].first]<<" , "<<arr[aux[l].second]<<" , "<<arr[aux[r].first]<<" , "<<arr[aux[l].second];
//         }
//         else if((aux[l].sum+aux[r].sum)<x)
//             i++;
//         else if((aux[l].sum+aux[r].sum)>x)
//             j--;
//     }
// }

// int main()
// {
//     int arr[] = { 10, 20, 30, 40, 1, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int X = 91;
   
//     findFourElements(arr, n, X);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 

class pairSum {
public:
    
    int first;
    int sec;
    int sum;
};
  
int compare(const void* a, const void* b)
{
    return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
}
 

bool noCommon(pairSum a, pairSum b)
{
    if (a.first == b.first || a.first == b.sec
        || a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}
 
void findFourElements(int arr[], int n, int X)
{
    int i, j;

    int size = (n * (n - 1)) / 2;
    pairSum aux[size];
 
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }
 
    qsort(aux, size, sizeof(aux[0]), compare);
 
    i = 0;
    j = size - 1;
    while (i < size && j >= 0) {
        if ((aux[i].sum + aux[j].sum == X)
            && noCommon(aux[i], aux[j])) {
            cout << arr[aux[i].first] << ", "
                 << arr[aux[i].sec] << ", "
                 << arr[aux[j].first] << ", "
                 << arr[aux[j].sec] << endl;
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}
 
int main()
{
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
   
    findFourElements(arr, n, X);
    return 0;
}
