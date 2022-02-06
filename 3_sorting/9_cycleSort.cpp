#include<bits/stdc++.h>
using namespace std;

void cycleSort(int arr[], int n){
    int cycle_start=0;
    for(cycle_start=0;cycle_start<n;cycle_start++){
        int pos=cycle_start;
        int curr_item=arr[cycle_start]; // take an item 
        for(int i=cycle_start+1;i<n;i++){
            if(curr_item>arr[i])
                pos++; // find its correct position in the sorted array
        }
        if(pos==cycle_start)
            continue; // leave it, if it is already in its correct position
        while(arr[pos]==curr_item)
            pos++;    // increment the pos if duplicates are found     
        if(arr[pos]!=curr_item)
            swap(arr[pos],curr_item); // place the item at its correct position 

        while(pos!=cycle_start){ // continue the cycle untill you reach back the cycle_start again
            pos = cycle_start; 
            for(int i=cycle_start+1;i<n;i++){
                if(curr_item>arr[i])
                    pos++;
            }
            while(arr[pos]==curr_item)
                pos++;  
            if(arr[pos]!=curr_item)
                swap(arr[pos],curr_item);            
        }
    }
}

int main(){
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
 
    cout << "After sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}