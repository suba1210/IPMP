#include<bits/stdc++.h>
using namespace std;

class SegmentTreeSumQuery{
public:
    vector<int> sTree;
    SegmentTreeSumQuery(int size){
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
        sTree[ind] = sTree[2*ind+1] + sTree[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r){
        // no overlap
        // low high l r || l r low high
        if(r < low || high < l)
            return 0;
        
        // complete overlap
        // l low high r
        if(low >= l && high <=r)
            return sTree[ind];

        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left + right;       
    }

    void pointUpdate(int ind, int low, int high, int targetInd, int value){
        if(low==high){
            sTree[ind] = value;
            return;
        }
        int mid = (low + high)/2;

        if(targetInd <= mid){
            pointUpdate(2*ind+1, low, mid, targetInd, value);
        } else {
            pointUpdate(2*ind+2, mid+1, high, targetInd, value);
        }
        sTree[ind] = sTree[2*ind+1] + sTree[2*ind+2];
    }
};

int main(){
    vector<int> arr = {2, 1, 9, -16, 3, 7};
    int size = arr.size();
    
    // segment tree array
    SegmentTreeSumQuery st(size);
    st.build(0, 0, size-1, arr);
    cout<<st.query(0, 0, size-1, 1, 4)<<" ";
    st.pointUpdate(0, 0, size-1, 3, 8);
    cout<<st.query(0, 0, size-1, 1, 4)<<" ";
}
