#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;

vector<int> distances;
vector<int> visited;
void bfs_visit(Graph &adj, int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    distances[s] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto n : adj[t])
        {
            if (visited[n] == 0)
            {
                visited[n] = 1;
                distances[n] = distances[t] + 1;
                q.push(n);
            }
        }
        visited[t] = 2;
    }
}

void bfs(Graph &adj, int s)
{

    for (int i = 0; i < visited.size(); i++)
    {

        if (visited[i] == 0)
        {

            bfs_visit(adj, i);
        }
    }
}

int main()
{
    // Your code here
    int v;
    int e;
    cin >> v >> e;
    distances.resize(v);
    visited.resize(v);
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int n1;
        int n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    bfs(adj,0);
    for (int i = 0; i < v; i++)
    {
        cout << i<<": " << distances[i]<< endl;
    }

    return 0;
}