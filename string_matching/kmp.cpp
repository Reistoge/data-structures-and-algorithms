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
            k = pi[k-1];
        }
        if (P[k] == P[q])
        {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

vector<int> KMP(string &T, string &P)
{
    vector<int> r =  vector<int>(1);
    int n = T.size();
    int m = P.size();
    auto pi = lps(P, m);
    int q = 0;
    for (int i = 0; i < n; i++){
        while(q > 0 && (P[q] != T[i] )){
            q = pi[q-1];
        }
        if(P[q] == T[i]){
            q++;
        }
        if( q == m){
            cout << "found at " << (i-m+1) << endl;
            q = pi[q-1];
        }

    }
    return r;
}

int main()
{

    string P;
    //string T;

    //cin >> T >> P;
    cin >> P;

    auto r = lps(P,P.size());
    for(auto x : r){
        cout << x << " ";
    }

    return 0;
}