#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &V, vector<bool> &visited, int v, int depth, bool &checked)
{
    if (visited[v])
    {
        return;
    }

    if (depth == 5 || checked)
    {
        checked = true;

        return;
    }
    // cout << depth << "\n";

    visited[v] = true;

    for (int v1 : V[v])
    {
        DFS(V, visited, v1, depth + 1, checked);
    }

    visited[v] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> V(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        V[v1].push_back(v2);
        V[v2].push_back(v1);
    }

    bool checked = false;

    for (int i = 0; i < N; i++)
    {
        if (checked)
        {
            break;
        }

        vector<bool> visited(N, false);

        DFS(V, visited, i, 1, checked);
    }

    if (checked)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}