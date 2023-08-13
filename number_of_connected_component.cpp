#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> arr[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;

    for (int v : arr[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : arr[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // bfs(1);

    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int v : arr[i])
        {
            if (!visited[i])
            {
                dfs(1);
                cc++;
            }
        }
    }

    cout << endl
         << "Number of connected component: " << cc << endl;
    ;

    return 0;
}