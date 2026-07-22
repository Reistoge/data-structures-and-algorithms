#include <bits/stdc++.h>
using namespace std;

vector<int> lps(string &P, int m)
{
    vector<int> pi = vector<int>(m);
    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++)
    {

        while (k > 0 && P[k] != P[q])
        {
            k = pi[k - 1];
        }
        if (P[k] == P[q])
        {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}
int main()
{
    // Your code here

    return 0;
}