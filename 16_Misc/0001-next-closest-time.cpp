class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    char findNext(char currDigit, string& digits, char upperLimit){
        if(currDigit == upperLimit)
            return digits[0];
        
        int nextIndex = upper_bound(digits.begin(), digits.end(), currDigit) - digits.begin();
        if(nextIndex!=digits.size() && digits[nextIndex] <= upperLimit){
            return digits[nextIndex];
        } else {
            return digits[0];
        }
    }

    bool isGreater(string result, string time){
        int timeInMinutes = stoi(time.substr(0, 2))*60 + stoi(time.substr(3,2));
        int resultInMinutes = stoi(result.substr(0, 2))*60 + stoi(result.substr(3,2));

        return resultInMinutes > timeInMinutes;
    }

    string nextClosestTime(string &time) {
        string digits = time;
        string result = time;
        sort(digits.begin(), digits.end());

        result[4] = findNext(result[4], digits, '9');
        if(isGreater(result, time))
            return result;

        result[3] = findNext(result[3], digits, '5');
        if(isGreater(result, time))
            return result;

        if(result[0] == '2')
            result[1] = findNext(result[1], digits, '3');
        else
            result[1] = findNext(result[1], digits, '9');
        if(isGreater(result, time))
            return result;

        result[0] = findNext(result[0], digits, '2');
        if(isGreater(result, time))
            return result;
        return result;
    }
};