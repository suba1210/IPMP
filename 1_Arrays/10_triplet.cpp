#include<bits/stdc++.h>
using namespace std;

vector<int> returnPerfectSqs(int n)
{
    vector<int> perfect;

    for(int i=1;i<=n;i++)
    {
        perfect.push_back(pow(i,2));
    }

    return perfect;
}

int  tripletAppro1(int n)
{
    int i,j,x,y,ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            x = (i*i)+(j*j);

            y = sqrt(x);

            if(((y*y)==x) && (y<=n))
            {
                ans++;
            }

        }
    }

    return ans;
}

int tripletAppro2(int n)
{
    vector<int> perfectSquares = returnPerfectSqs(n);

    int i,j,a,b,c,aSq,bSq,cSq,ans=0;

    for(i=1;i<=n;i++)
    {
        a=i;
        aSq = pow(i,2);
        for(j=0;j<perfectSquares.size();j++)
        {
            cSq = perfectSquares[j];
            bSq = abs(cSq-aSq);
            b = sqrt(bSq);
            c = sqrt(cSq);

            if(c<a|| find(perfectSquares.begin(),perfectSquares.end(),bSq)==perfectSquares.end() )
            {
                continue;
            }
            
            if((a<=b)&&(b<=c)&&((aSq+bSq)==cSq))
                ans++;
        }
    }

    return ans;
}

int main()
{
    int n=10;
    cout<<tripletAppro1(n)<<" "<<tripletAppro2(n);
}