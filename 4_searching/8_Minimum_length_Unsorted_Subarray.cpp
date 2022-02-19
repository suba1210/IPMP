// Approach: gfg explanation is bestt
// Learnings : See what is asked in the problem, and think how can we get it, 
//              even if a small clue is found, use it wisely!!!


#include<bits/stdc++.h>
using namespace std;

void printUnsorted(int arr[], int size){
    int start_of_unsorted = 0, end_of_unsorted=size-1;

    // find the first element (from left to right) which is smaller than its previous
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1])
        {
            start_of_unsorted=i;
            break;
        }
    }

    // find the first element (from right to left) which is smaller than its previous
    for(int i=size-1;i>=1;i--){
        if(arr[i]<arr[i-1]){
            end_of_unsorted = i;
            break;
        }
    }

    int min = start_of_unsorted;
    int max = end_of_unsorted;

    // find min and max from s to e
    for(int i=start_of_unsorted; i<=end_of_unsorted;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }

    //find 0 to s-1 if smthing less than min, if so expand s
    for(int i=0;i<start_of_unsorted;i++){
        if(arr[i]<min){
            min=arr[i];
            start_of_unsorted = i;
        }
    }

    //find e+1 to n-1 if smthing more than max, if so expand e
    for(int i=end_of_unsorted+1;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
            end_of_unsorted=i;
        }
    }

    cout<<"start_of_unsorted = "<<start_of_unsorted<<endl;
    cout<<"end_of_unsorted = "<<end_of_unsorted;
    
}

int main(){
    int arr[] = {20, 30, 25, 40, 32, 31, 35, 50, 60};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printUnsorted(arr, arr_size);
    return 0;    
}
