#include <bits/stdc++.h>
using namespace std;

void findNextPermute(int v[], int N)
{
    int ind=0;

    for (int i = N - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            ind = i;
            break;
        }
    }
    for (int i = N - 1; i > ind; i--)
    {
        if (v[i] > v[ind])
        {
            swap(v[i], v[ind]);
            ind++;
            break;
        }
    }
    for (int i = 0; i < (N - ind) / 2; i++)
        swap(v[i + ind], v[N - i - 1]);

    cout << "Next Permutation :";

    for (int i = 0; i < N; i++)
        cout << v[i] << " ";
}

int main()
{
    int digits[] = {3, 2, 1};
    int n = sizeof(digits) / sizeof(digits[0]);
    findNextPermute(digits, n);
    return 0;
}