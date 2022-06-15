class triplet{
public:
    int value, aPos, vPos;
    triplet(int value, int aPos, int vPos){
        this->value = value;
        this->aPos = aPos;
        this->vPos = vPos;
    }
};

struct customCompare{
  bool operator()(triplet& a, triplet& b){
    return a.value > b.value;
  } 
};

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> result;
        priority_queue<triplet, vector<triplet>, customCompare> pq;
        
        for(int i=0;i<arr.size();i++){
            triplet t(arr[i][0], i, 0);
            pq.push(t);
        }
        
        while(!pq.empty()){
            triplet temp = pq.top();
            pq.pop();
            result.push_back(temp.value);
            if(temp.vPos + 1 < arr[temp.aPos].size()){
                triplet nextVal = triplet(arr[temp.aPos][temp.vPos+1], temp.aPos, temp.vPos+1);
                pq.push(nextVal);
            }
        }
        
        return result;
    }
};