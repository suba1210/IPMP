class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for(auto x : intervals){
            start.push_back(x.start);
            end.push_back(x.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0, e = 0, count=0, result=INT_MIN;

        while(s<start.size() && e<end.size()){
            if(start[s]<end[e]){
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            result = max(count, result);
        }
        return result;
    }
};