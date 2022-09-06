#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
public:
    vector<int> ft;
    FenwickTree(int size){
        ft.resize(size);
    }

    void update(int ind, int val)
    {
        for(int i = ind; i<ft.size(); i += (i & (-i)))
            ft[i] += val;
    }

    int sumQuery(int i){ // prefix sum between 0 and i
        int sum = 0;
        while(i > 0){
            sum += ft[i];
            i = (i & (i-1)); // move to previous index
        }
        return sum;
    }

    int rangeSumQuery(int l, int r){
        return sumQuery(r) - sumQuery(l-1); 
    }
};

int main(){
    vector<int> arr = {1, 3, 5};
    FenwickTree FenTree(arr.size()+1);

    for(int i=0;i<arr.size();i++){
        FenTree.update(i+1, arr[i]);
    }

    cout<<FenTree.rangeSumQuery(1, 3)<<" ";
    FenTree.update(2, 2);
    cout<<FenTree.rangeSumQuery(1, 3)<<" ";
}