class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        ans |= (n&1);
        for(int i=0;i<31;i++){
            n>>=1;
            ans<<=1;
            ans |= (n&1);
        }
        return ans;
    }
};