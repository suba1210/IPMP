class Solution{
  public:
    int assignMiceHoles(int n , int m[] , int h[]) {
        sort(m, m+n);
        sort(h, h+n);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx, abs(m[i]-h[i]));
        }
        
        return mx;
    }
};