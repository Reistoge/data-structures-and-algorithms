#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, vector<int> &v,int n){
    v[n] = 1; 
    cout << n << " ";
    for(int node : adj[n]){
        if(v[node] == 0){
            dfs(adj, v, node);
            cout <<endl;
        }
    }

}
int main() {
    // Your code here
    int n; int c;
    cin >> n >> c;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < c; i++)
    {
        int n1; int n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);

    }
   

    vector<int> v(adj.size(),0);
    //cout << adj.size();
    dfs(adj,v,0);


    return 0; 
}