#include<bits/stdc++.h>
using namespace std;

class SegmentTreeMinQuery{
public:
    vector<int> sTree;
    SegmentTreeMinQuery(int size){
        sTree.resize(4*size);
    }
    
    void build(int ind, int low, int high, vector<int>& arr){
        if(low==high){
            sTree[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        sTree[ind] = min(sTree[2*ind+1], sTree[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r){
        // no overlap
        // low high l r || l r low high
        if(r < low || high < l)
            return INT_MAX;
        
        // complete overlap
        // l low high r
        if(low >= l && high <=r)
            return sTree[ind];

        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return min(left, right);       
    }

    void pointUpdate(int ind, int low, int high, int targetInd, int value, vector<int>& arr){
        if(low==high){
            sTree[ind] = value;
            return;
        }
        int mid = (low + high)/2;

        if(targetInd <= mid){
            pointUpdate(2*ind+1, low, mid, targetInd, value, arr);
        } else {
            pointUpdate(2*ind+2, mid+1, high, targetInd, value, arr);
        }
        sTree[ind] = min(sTree[2*ind+1], sTree[2*ind+2]);
    }
};

int main(){
    vector<int> arr = {2, 1, 9, -16, 3, 7};
    int size = arr.size();
    
    // segment tree array
    SegmentTreeMinQuery st(size);
    st.build(0, 0, size-1, arr);
    cout<<st.query(0, 0, size-1, 1, 4)<<" ";
    st.pointUpdate(0, 0, size-1, 3, 8, arr);
    cout<<st.query(0, 0, size-1, 1, 4)<<" ";
}