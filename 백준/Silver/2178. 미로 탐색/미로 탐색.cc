#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;
void BFS(vector<vector<int>> &T)
{
    vector<vector<bool>> visited(T.size(), vector<bool>(T[0].size(), false));

    queue<node> Q;

    Q.push(node(0, 0));

    while (!Q.empty())
    {
        node C = Q.front();
        Q.pop();
        if (visited[C.first][C.second])
        {
            continue;
        }

        visited[C.first][C.second] = true;

        if (C.first - 1 >= 0 && T[C.first - 1][C.second] && !visited[C.first - 1][C.second])
        {
            Q.push(node(C.first - 1, C.second));
            T[C.first - 1][C.second] = T[C.first][C.second] + 1;
        }
        if (C.second - 1 >= 0 && T[C.first][C.second - 1] && !visited[C.first][C.second - 1])
        {
            Q.push(node(C.first, C.second - 1));
            T[C.first][C.second - 1] = T[C.first][C.second] + 1;
        }
        if (C.first + 1 < T.size() && T[C.first + 1][C.second] && !visited[C.first + 1][C.second])
        {
            Q.push(node(C.first + 1, C.second));
            T[C.first + 1][C.second] = T[C.first][C.second] + 1;
        }
        if (C.second + 1 < T[0].size() && T[C.first][C.second + 1] && !visited[C.first][C.second + 1])
        {
            Q.push(node(C.first, C.second + 1));
            T[C.first][C.second + 1] = T[C.first][C.second] + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> T(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++)
        {
            T[i][j] = S[j] - '0';
        }
    }

    BFS(T);

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << T[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    cout << T[N - 1][M - 1] << "\n";
}