#include <bits/stdc++.h>
using namespace std;

// this is a simplified version of KMP + LPS which uses a shortcut to combine in a one and only method
// the approach is to basically combine the pattern + # + text where "#" is a symbol that will not appear in pattern or text
// lps for this kind of text will basically have indices in range of 0 to | p | where lps[i] == |p| is that the pattern is found on a index i - 2*M  
vector<int> find_pattern(string &t, string &p)
{
    int n = t.size();
    int m = p.size();
    string aux = p + "#" + t;
    vector<int> pi = vector<int>(m + n + 1);
    int k = 0;

    for (int i = 1; i < aux.size(); i++)
    {

        while (k > 0 && aux[k] != aux[i])
        {
            k = pi[k - 1];
        }
        if (aux[k] == aux[i])
        {
            k++;
        }
        pi[i] = k;
        if (k == m)
        {
            cout << "found at " << (i - (2*m)) << endl;
        }
    }
    return pi;
}
int main()
{
    // Your code here
    string t, p;
    cin >> t >> p;
    auto lps = find_pattern(t, p);
    for (auto x : lps)
    {
        cout << x << " ";
    }
    return 0;
}