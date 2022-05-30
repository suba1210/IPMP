class Solution {
public:
    void combinations(vector<vector<int> >& result, vector<int>& data, vector<int>& candidates, int target, int index){
        if(index == candidates.size()){
            if(target==0){
                result.push_back(data);
            }
            return;
        }
        if(candidates[index]<=target){
            data.push_back(candidates[index]);
            combinations(result, data, candidates, target-candidates[index], index);
            data.pop_back();
        }
        combinations(result, data, candidates, target, index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> data;
        combinations(result, data, candidates, target, 0);
        return result;
    }
};