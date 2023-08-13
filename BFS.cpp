#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> arr[N];
bool visited[N];
int level[N];

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << "Visiting Node: " << u << endl;

        for (int v : arr[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
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

    bfs(1);

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Level of " << i << " " << level[i] << endl;
    }

    return 0;
}