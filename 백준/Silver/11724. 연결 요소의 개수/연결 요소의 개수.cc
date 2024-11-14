#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>> &V, vector<bool> &B, int v)
{
    if (B[v])
        return false;

    B[v] = true;

    for (int i = 0; i < V[v].size(); i++)
    {
        DFS(V, B, V[v][i]);
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<bool> B(N + 1, false);
    B[0] = true;
    vector<vector<int>> V(N + 1, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        V[v1].push_back(v2);
        V[v2].push_back(v1);
    }

    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        // cout << i << " -> ";
        // for (int j = 0; j < V[i].size(); j++)
        // {
        //     cout << V[i][j] << " ";
        // }

        // cout << endl;

        if (DFS(V, B, i))
        {
            count++;
        }
    }

    cout << count << "\n";
}