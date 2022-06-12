int Solution::bulbs(vector<int> &A) {
    int size = A.size();
    int count = 0, state=0;
    for(int i=0;i<size;i++){
        if(A[i]==state){
            count++;
            state = 1 - state;
        }
    }
    return count;
}
