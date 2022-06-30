#include <bits/stdc++.h>
using namespace std;
int main ()
{

   ios_base::sync_with_stdio(false);//these lines
    cin.tie(NULL);                  // allows faster input
    int testCases = 5; //number of test cases
    while(testCases--)
    {
       long long m , n;  // can this algorithm handle 64 bit input??
       short digits[100000]; // to store digits
       cin>>m>>n;
       for(long long i=m-1;i>0;i--)
       {
           digits[i]=min((long long)9,n-1); // for eg: if n=4, m=4, then digits[3]=3 => 1003
           n-=digits[i]; // decrease sum of remaining digits
       }
       digits[0]=n; //assign the left most with the remainder

       for( long long i=0;i<m;i++)//output
            cout<<digits[i];

       cout<<endl<<endl<<endl; // to sperate test cases
     }
}
