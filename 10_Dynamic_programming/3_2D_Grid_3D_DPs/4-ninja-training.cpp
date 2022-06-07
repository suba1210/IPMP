#include<bits/stdc++.h>
using namespace std;

// recursion tc = O(n^3) sc = O(n)
int funcRecur(int day, int last, vector<vector<int>> &points){
    if(day==0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxx = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxx = max(maxx, points[day][i] + funcRecur(day-1,i,points));
        }
    }
    return maxx;
}

// memoization tc = O(n*3) sc = O(n)+O(n)
int funcDpMemo(int day, int last, vector<vector<int> >& dp, vector<vector<int>> &points){
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    if(day==0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi, points[0][i]);
        }
        return dp[day][last] = maxi;
    }
    int maxx = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxx = max(maxx, points[day][i] + funcDpMemo(day-1,i,dp,points));
        }
    }
    return dp[day][last] = maxx; 
}

//tabulation tc = O(n*3) sc = O(n)
int funcDpMemo(int day, int last, vector<vector<int> >& dp, vector<vector<int>> &points){
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max

    for(int day=1;day<points.size();day++){
        for(int i=0;i<=points[0].size();i++){
            int maxx;
            if(i!=last){
                if(points[day][i] + dp[day-1][last] >= maxi){
                    maxx = i;
                    maxi = max(maxi, points[day][i] + dp[day-1][last]);
                }
            }
            last = maxx;
        }
    }
}

// space optimisation for tabulation space O(4) => O(1)
int ninjaTraining(int n, vector<vector<int>> &points){
  vector<int> prev(4, 0);
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    vector<int> dp(4, 0);
    for (int last = 0; last < 4; last++) {
      dp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + prev[task];
          dp[last] = max(dp[last], activity);
        }
      }
    }
    prev = dp;
  }
  return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //return funcRecur(n-1, 3 ,points);
    vector<vector<int> > dp(n, vector<int>(4,-1));
    return funcDpMemo(n-1, 3, dp, points);
}

int main() {

  vector < vector < int > > points = {{10,40,70},
                                      {20,50,80},
                                      {30,60,90}};

  int n = points.size();
  cout << ninjaTraining(n, points);
}
