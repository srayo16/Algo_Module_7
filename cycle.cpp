#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> arr[N];
int visited[N];
int cycle = 0;
bool dfs(int u, int p = -1)
{
    bool cycle = false;
    visited[u] = true;

    for (int v : arr[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        cycle = cycle | dfs(v, u);
    }
    return cycle;
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

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle = isCycle | dfs(i);
    }

    if (isCycle)
    {
        cout << "Cycle Detected!" << endl;
    }
    else
    {
        cout << "No Cycle Detected!" << endl;
    }

    // dfs(1);

    // if (dfs(1, -1))
    // {
    //     cout << "Cycle Detected!" << endl;
    // }
    // else
    // {
    //     cout << "No Cycle Detected!" << endl;
    // }

    return 0;
}