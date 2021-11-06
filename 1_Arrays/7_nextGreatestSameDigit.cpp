#include<bits/stdc++.h>
using namespace std;

void findNext(char digits[], int n)
{
    int i,j;

    for(i=n-1;i>0;i--)
    {
        if(digits[i]>digits[i-1])
        {
            break;
        }
    }

    if(i==0)
    {
        cout<<"Next number is not possible!";
        return;
    }

    int x = digits[i-1], smallest = i;

    for(j=i+1;j<n;j++)
    {
        if(digits[j]>x && digits[j]<digits[smallest])
        {
            smallest = j;
        }
    }

    swap(digits[smallest],digits[i-1]);

    sort(digits+i,digits+n);

    cout<<"Next number : "<<digits;

    return;

}

int main()
{
    char digits[] = "534976";
    int n = strlen(digits);
    findNext(digits, n);
    return 0;
}