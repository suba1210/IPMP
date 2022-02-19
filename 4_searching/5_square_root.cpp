// ->  do binary search from from 1 to n/2 whether that number could be the 
//     square root of the given number, here main problem is to find the floor of the square root,
//     for eg. in cases like 10, sqrt is 2.222 ans = 2, so we have to assign <= value to ans everytime and do normal binary search

#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int x){
    int start = 1, end = x/2, ans;

    while(start<=end){
        int mid = (start+end)/2;
        int sqr = mid*mid;

        if(sqr==x)
            return mid;
        else if(sqr<=x){
            start = mid+1;
            ans=mid;
        }
        else if(sqr>x)
        {
            end = mid-1;
        }
    }

    return ans;
}

int main(){
    int x = 16;
    cout << floorSqrt(x) << endl;
    return 0;    
}