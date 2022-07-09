// In this problem the size of the ft is 1 + max element, here we store numbers like hash

class FenwickTree{
public:
    vector<int> ft;
    FenwickTree(int size){
        ft.resize(size);
    }

    void update(int i, int value){
        while(i < ft.size()){
            ft[i] += value;
            i += (i & (-i)); // move to next index
        }
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


class Solution {
public:
    int createSortedArray(vector<int>& que) {
        int size = *max_element(que.begin(), que.end());
        FenwickTree ft(size+1);
        
        int cost = 0;
        for(auto x : que){
            int left = ft.rangeSumQuery(0, x-1);
            int right = ft.rangeSumQuery(x+1, size);
            cost = (cost + min(left, right)) % (int)(1e9 + 7);
            ft.update(x, 1);
        }
        
        return cost;
        
    }
};