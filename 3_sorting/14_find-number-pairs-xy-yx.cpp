#include<bits/stdc++.h>
using namespace std;

int count(int Y[], int noOfY[], int yn, int x){

    if(x==0)
        return 0;

    if(x==1)
        return noOfY[0];

    int* idx = upper_bound(Y, Y+yn, x);
    int ans = (Y+yn) - idx;

    ans += noOfY[0] + noOfY[1];

    if(x==2){
        ans -= (noOfY[3] + noOfY[4]);
    }

    if(x==3)
        ans += noOfY[2];

    return ans;

}

int  countPairs(int X[], int Y[], int xn, int yn){

    int noOfY[5] = {0};

    for(int i=0;i<yn;i++){
        if(Y[i]<5)
            noOfY[Y[i]]++;
    }

    sort(Y, Y+yn);

    int total_pairs=0;

    for(int i=0;i<xn;i++){
        total_pairs += count(Y, noOfY, yn, X[i]);
    }

    return total_pairs;

}

int main(){
    int X[] = { 2, 1, 6 };
    int Y[] = { 1, 5 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
 
    cout << "Total pairs = " <<countPairs(X, Y, m, n);
 
    return 0;   
}