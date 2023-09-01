// Brian Kernighan algorithm
// Traverse only through set bits
// When we do n AND n-1, we will get a number with last set bit removed from n
int countSetBits(int n){
    int count=0;
    while(n>0){
        n = n&(n-1);
        count++;
    }
    return count;
}