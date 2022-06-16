#include<bits/stdc++.h>
using namespace std;

class info{
public:
    int open, close, full;
    info(int open, int close, int full){
        this->open = open;
        this->close = close;
        this->full = full;
    }
    info(){
        this->open = 0;
        this->close = 0;
        this->full = 0;       
    }
};

class SegmentTree{
public:
    vector<info> st;
    SegmentTree(int size){
        st.resize(4*size);
    }

    info merge(info left, info right){
        info ans(0, 0 , 0);
        ans.full = left.full + right.full + min(left.open, right.close);
        ans.open = left.open + right.open - min(left.open, right.close);
        ans.close = left.close + right.close - min(left.open, right.close);
        return ans;
    }

    void build(int ind, int low, int high, string brackets){
        if(low == high) {
            st[ind] = info(brackets[low] == '(', brackets[low] == ')', 0);
            return;           
        }
        
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, brackets);
        build(2*ind+2, mid+1, high, brackets);

        st[ind] = merge(st[2*ind+1], st[2*ind+2]);
    }

    info query(int ind, int low, int high, int l, int r){

        // no overlap
        // l r low high
        if(r < low || high < l){
            return info(0,0,0);
        }

        // complete overlap
        if( low >= l && high <= r){
            return st[ind];
        }

        // partial overlap
        int mid = (low+high)/2;
        info left = query(2*ind+1, low, mid, l, r);
        info right = query(2*ind+2, mid+1, high, l, r);
        return merge(left, right);
    }

};

int main(){
    string str = "())(())(())(";
    SegmentTree seg(str.length());

    seg.build(0, 0, str.length()-1, str);
    cout<<seg.query(0, 0, str.length()-1, 3, 10).full;

}