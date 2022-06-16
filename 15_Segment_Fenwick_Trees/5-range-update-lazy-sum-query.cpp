#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<int> st, lazy;
    SegmentTree(int size){
        st.resize(4*size);
        lazy.resize(4*size);
        
    }

    void build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            st[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        st[ind] = st[2*ind+1] + st[2*ind+2];
    }

    void update(int ind, int low, int high, int l, int r, int val){
        // update the previous remaining updates 
        // and propagate downwards
        if(lazy[ind]!=0) {
            st[ind] += (high - low + 1)*lazy[ind]; // number of nodes in the range of that node ( high - low + 1)
            //propagate the lazy updates downwards
            // for the remaining nodes to get updated
            if(low != high) { // if low == high, then it is a leaf node, it won't have children, in all other cases there will child nodes
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            } // children updated
            lazy[ind] = 0;
        }

        // no overlap
        // low high l r || l r low high
        if(r < low || high < l){
            return;
        }

        // complete overlap
        // l low high r
        if(l <= low  && high <= r){
            st[ind] += (high - low + 1)*val; // number of nodes in the range of that node ( high - low + 1)

            // if not leaf node
            if(low != high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;               
            }
            return;
        }

        // partial overlap
        int mid = (low + high)/2;
        update(2*ind+1, low, mid, l, r, val);
        update(2*ind+2, mid+1, high, l, r, val);
        st[ind] = st[2*ind+1] + st[2*ind+2];
    } 

    int query(int ind, int low, int high, int l, int r){
        // update the previous remaining updates 
        // and propagate downwards
        if(lazy[ind]!=0) {
            st[ind] += (high - low + 1)*lazy[ind]; // number of nodes in the range of that node ( high - low + 1)
            //propagate the lazy updates downwards
            // for the remaining nodes to get updated
            if(low != high) { // if low == high, then it is a leaf node, it won't have children, in all other cases there will child nodes
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            } // children updated
            lazy[ind] = 0;
        }

        // no overlap return 0
        // low high l r || l r low high
        if(r < low || high < l){
            return 0;
        }


        // complete overlap
        // l low high r
        if(l <= low  && high <= r){
            return st[ind];
        }


        // partial overlap
        int mid = (low + high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return right + left;
    }
};

int main(){
    vector<int> arr = {1, 4, 2, 1, 3, 1};
    int size = arr.size();

    SegmentTree seg(size);
    seg.build(0, 0, size-1, arr);
    cout<<seg.query(0, 0, size-1, 0, 3)<<" ";
    seg.update(0, 0, size-1, 0, 3, 2);
    cout<<seg.query(0, 0, size-1, 0, 3)<<" ";

}