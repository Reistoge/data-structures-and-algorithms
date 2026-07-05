#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &mtx, vector<vector<int>> &v, int i, int j)
{

    queue<pair<int, int>> q;
    v[i][j] = 1;
    int m = mtx.size();
    int n = mtx[0].size();
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int left = p.second - 1;
        int right = p.second + 1;
        int up = p.first + 1;
        int down = p.first - 1;
        if ((left < n) && (left >= 0) && v[p.first][left] == 0 && mtx[p.first][left] != 0)
        {
            q.push({p.first, left});
            v[p.first][left] = 1;
        }
        if ((right < n && right >= 0) && v[p.first][right] == 0 && mtx[p.first][right] != 0)
        {
            q.push({p.first, right});
            v[p.first][right] = 1;
        }
        if ((up >= 0 && up < m) && v[up][p.second] == 0 && mtx[up][p.second] != 0)
        {
            q.push({up, p.second});
            v[up][p.second] = 1;
        }
        if ((down >= 0 && down < m) && v[down][p.second] == 0 && mtx[down][p.second] != 0)
        {
            q.push({down, p.second});
            v[down][p.second] = 1;
        }
    }
    v[i][j] = 2;
}

int count_isles(vector<vector<int>> &mtx, int m, int n)
{
    int isles = 0;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mtx[i][j] != 0 && v[i][j] == 0)
            {
                bfs(mtx, v, i, j);
                isles++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return isles;
}

int main()
{
    // Your code here
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mtx(m, vector<int>(n, 0));

    int p = 0;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        mtx[x][y] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int result = count_isles(mtx, m, n);
    cout << result;
    return 0;
}