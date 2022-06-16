#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

int constructST(int arr[], int st[], int ss, int se, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    st[si] = gcd(constructST(arr, st, ss, mid, si * 2 + 1), constructST(arr, st, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *constructSegmentTree(int arr[], int n) {
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    int *st = new int[size];
    constructST(arr, st, 0, n - 1, 0);
    return st;
}

// Solution 
class Solution
{
    public:
    
    int findRangeHelper(int ind, int low, int high, int l, int r, int st[]){
        
        // no overlap
        // l r low high
        if(r < low || high < l){
            return 0;
        }
        
        // complete overlap
        // l low high r
        if( l <= low && high <= r ){
            return st[ind];
        }
        
        // partial overlap
        int mid = (low + high)/2;
        int left = findRangeHelper(2*ind+1, low, mid, l, r, st);
        int right = findRangeHelper(2*ind+2, mid+1, high, l, r, st);
        return gcd(left, right);
    }
    
    int findRangeGcd(int l, int r, int st[], int n) 
    {
        return findRangeHelper(0, 0, n-1, l, r, st);
    }
    
    void updateValueHelper(int ind, int low, int high, int index, int new_val, int st[]){
        if(low == high){
            st[ind] = new_val;
            return;
        }
        
        int mid = (low+high)/2;
        if(index <= mid){
            updateValueHelper(2*ind+1, low, mid, index, new_val, st);
        } else {
            updateValueHelper(2*ind+2, mid+1, high, index, new_val, st);
        }
        st[ind] = gcd(st[2*ind+1], st[2*ind+2]);
        
    }
    
    void updateValue(int index, int new_val, int *arr, int st[], int n) 
    {
        updateValueHelper(0, 0, n-1, index, new_val, st);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int *st = constructSegmentTree(a, n);
        int type;
        while (q--) {
            cin >> type;

            if (type == 0) {
                int l, r;
                cin >> l >> r;
                Solution obj;
                cout << obj.findRangeGcd(l, r, st, n) << endl;
            } else {
                int ind, val;
                cin >> ind >> val;
                Solution obj;
                obj.updateValue(ind, val, a, st, n);
            }
        }
    }

    return 0;
} 