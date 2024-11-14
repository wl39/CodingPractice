#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> &V, vector<bool> &visited, int v)
{
    if (visited[v])
    {
        return;
    }

    cout << v << " ";

    visited[v] = true;

    for (int v1 : V[v])
    {
        DFS(V, visited, v1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, S;

    cin >> N >> M >> S;

    vector<vector<int>> V(N + 1, vector<int>());
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        V[v1].push_back(v2);
        V[v2].push_back(v1);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(V[i].begin(), V[i].end());
    }

    DFS(V, visited, S);

    visited = vector<bool>(N, false);
    queue<int> Q;

    visited[S] = true;

    cout << "\n"
         << S << " ";
    for (int v : V[S])
    {
        Q.push(v);
    }

    while (!Q.empty())
    {
        if (visited[Q.front()])
        {
            Q.pop();
            continue;
        }

        visited[Q.front()] = true;

        cout << Q.front() << " ";

        for (int v : V[Q.front()])
        {
            Q.push(v);
        }

        Q.pop();
    }
    cout << "\n";
}