class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int aPtr = 0, bPtr = 0;
        vector<int> temp(2);
        vector<vector<int>> result;
        
        while(aPtr < firstList.size() && bPtr<secondList.size()){
            if(firstList[aPtr][1]>=secondList[bPtr][0] && firstList[aPtr][0]<=secondList[bPtr][1]){
                temp[0] = max(firstList[aPtr][0], secondList[bPtr][0]);
                temp[1] = min(firstList[aPtr][1], secondList[bPtr][1]);
                result.push_back(temp);
            }
            if(firstList[aPtr][1]<secondList[bPtr][1])
                aPtr++;
            else
                bPtr++;
        }
        return result;
    }
};
