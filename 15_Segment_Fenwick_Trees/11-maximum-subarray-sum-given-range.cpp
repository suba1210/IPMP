#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
    int maxSubarraySum;

    Node(){
        maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = INT_MIN;
    }
};

class SegmentTree{
public:
    vector<Node> seg;
    SegmentTree(int size){
        seg.resize(4*size);
    }

    Node merge(Node left, Node right){
        Node parent;
        parent.maxPrefixSum = max(left.maxPrefixSum, left.totalSum + right.maxPrefixSum);
        parent.maxSuffixSum = max(right.maxSuffixSum, right.totalSum + left.maxSuffixSum);
        parent.totalSum = left.totalSum + right.totalSum;
        parent.maxSubarraySum = max({left.maxSubarraySum, right.maxSubarraySum, left.maxSuffixSum + right.maxPrefixSum});
        return parent;
    }

    void build(int ind, int low, int high, vector<int> arr){
        if(low == high){
            seg[ind].maxPrefixSum = arr[low];
            seg[ind].maxSubarraySum = arr[low];
            seg[ind].maxSuffixSum = arr[low];
            seg[ind].totalSum = arr[low];
            return;
        }

        int mid = (low + high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }

    Node query(int ind, int low, int high, int l, int r, vector<int> arr){
        // no overlap
        // low high l r || l r low high
        if(r < low || high < l){
            return Node();
        }

        // complete overlap
        // l low high r
        if(low >= l && high <= r){
            return seg[ind];
        }

        // partial overlap
        int mid = (low + high)/2;
        Node left = query(2*ind+1, low, mid, l, r, arr);
        Node right = query(2*ind+2, mid+1, high, l, r, arr);
        return merge(left, right);
    }
};

int main(){
    vector<int> arr = { 1, 3, -4, 5, -2 };
    int size = arr.size();

    SegmentTree st(size);
    st.build(0, 0, size-1, arr);
    cout<<st.query(0, 0, size-1, 0, 4, arr).maxSubarraySum;
}