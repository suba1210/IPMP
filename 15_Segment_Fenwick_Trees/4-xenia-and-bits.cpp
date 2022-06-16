#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

class SegmentTree{
public:
    vector<ll> segtree;
    SegmentTree(ll size){
        segtree.resize(4*size+1);
    }

    void build(ll ind, ll low, ll high, vector<ll>& arr, bool orr){
        if(low==high){
            segtree[ind] = arr[low];
            return;
        }
        ll mid = (low+high)/2;
        build(2*ind+1, low, mid, arr, !orr);
        build(2*ind+2, mid+1, high, arr, !orr);
        if(orr)
            segtree[ind] = segtree[2*ind+1] | segtree[2*ind+2];
        else
            segtree[ind] = segtree[2*ind+1] ^ segtree[2*ind+2];
    }

    void update(ll ind, ll low, ll high, ll target, ll value, vector<ll>& arr, bool orr){
        if(low == high){
            segtree[ind] = value;
            return;
        }
        int mid = (low+high)/2;
        if(target <= mid)
            update(2*ind+1, low, mid, target, value, arr, !orr);
        else
            update(2*ind+2, mid+1, high, target, value, arr, !orr);


        if(orr)
            segtree[ind] = segtree[2*ind+1] | segtree[2*ind+2];
        else
            segtree[ind] = segtree[2*ind+1] ^ segtree[2*ind+2];
           
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin>>n>>q;
    ll size = pow(2,n);
    vector<ll> arr(size);

    for(ll i=0;i<size;i++){
        cin>>arr[i];
    }

    SegmentTree st(size);

    // if size is even, first query will be xor else it will or
    if(size%2 == 0)
        st.build(0, 0, size-1, arr, false);
    else
        st.build(0, 0, size-1, arr, true);

    // processing all queries
    while(q--){
        ll i, val;
        cin>>i>>val;
        i--; // change to zero based indexing
        if(n%2==0)
            st.update(0, 0, size-1, i, val, arr, false);
        else
            st.update(0, 0, size-1, i, val, arr, true);
        
        cout<<st.segtree[0]<<endl;
    }
  
}