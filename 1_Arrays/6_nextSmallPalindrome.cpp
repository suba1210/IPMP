#include<bits/stdc++.h>
using namespace std;

bool checkForAll9s(vector<int> &temp, int n)
{
    int i,count=0;
    
    for(auto x : temp)
    {
        if(x==9)
            count++;
    }
    if(n==count)
        return true;
    else
        return false;

}

void incrementMiddle(vector<int> &temp, int t1)
{
    while(temp[t1]==9)
    {
        temp[t1]=0;
        t1--;
    }
    temp[t1]++;
    return;
}

void generateNextPalindrome(vector<int> &num,int n)
{
    vector<int> temp(num);
    if(n%2) //for odd length
    {
        int middle = floor(n/2),i;

        if(temp[middle-1]>temp[middle+1])
        {
            for(i=0;i<middle;i++)
            {
                temp[n-i-1]=temp[i];
            }
            num = temp;
            return;
        }
        else if(temp[middle-1]<temp[middle+1])
        {
            temp[middle]++;
            for(i=0;i<middle;i++)
            {
                temp[n-i-1]=temp[i];
            }
            num = temp;
            return;
        }
        else
        {
            if(checkForAll9s(temp,n))
            {
                vector<int> nines;
                nines.push_back(1);
                for(i=0;i<n-1;i++)
                {
                    nines.push_back(0);
                }
                nines.push_back(1);
                num = nines;
                return;
            }
            int count=0;
            for(i=0;i<middle;i++)
            {
                if(temp[n-i-1]==temp[i])
                {
                    count++;
                }
            }            

            if(count==(floor(n/2)))
            {
                incrementMiddle(temp,middle);
            }
            else if(count<(floor(n/2)))
            {
                for(i=0;i<middle;i++)
                {
                    if(temp[n-i-1]==temp[i])
                    {
                        continue;
                    }
                    else{
                        
                    }
                }
            }

            
        }

    }

}

int main()
{
    vector<int> num{2,8,7,4,9};
 
    int n = num.size();
 
    generateNextPalindrome(num, n);

    for(auto x : num)
    {
        cout<<x<<" ";
    }
 
    return 0;

}