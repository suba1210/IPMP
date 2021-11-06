//Approach : Adding all profits one can get in consecutive days

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[],int n)
{
    int profit=0,i;
    for(i=1;i<n;i++)
    {
        if(price[i-1]<price[i])
        {
            profit += price[i]-price[i-1];
        }
    }

    return profit;
}

int main()
{
    int price[] = { 100, 180, 260, 310,40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price,n);
 
    return 0;    
}