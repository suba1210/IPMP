class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int num1 = 0, num2=0;
        sort(arr, arr+n);
        
        for(int i=0;i<n;i++){
            if(i%2){
                num1 = num1*10 + arr[i];
            } else {
                num2 = num2*10 + arr[i];
            }
        }
        
        return (long long int)(num1 + num2);
    }
};